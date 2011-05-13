#include "KinectController.h"

//--------------------------------------------------------------
bool isLeft(ofPoint *x1, ofPoint *x2) {
    return x1->x<x2->x ? true : false;
}

//--------------------------------------------------------------
bool isAbove(ofPoint *x1, ofPoint *x2) {
    return x1->y<x2->y ? true : false;
}

//--------------------------------------------------------------
KinectController::~KinectController() {
    ofLog(OF_LOG_VERBOSE, "KinectController::~KinectController()");
    kinect.setCameraTiltAngle(0);
	kinect.close();
}

//--------------------------------------------------------------
void KinectController::initialize(Ship *s, LookupMath *m) {
    ofLog(OF_LOG_VERBOSE, "KinectController::initialize(%x,%x)",(int)s,(int)m);
    angle = 0;
    kinect.init();
    kinect.open();
    kinect.setCameraTiltAngle(angle);
    trackingHands = false;
    
    nearThreshold = 230;
    farThreshold = 185;
    scaleFactor_w = ofGetWidth()/(float)kinect.width;
    scaleFactor_h = ofGetHeight()/(float)kinect.height;
    
    clrImg.allocate(kinect.width, kinect.height);
    depthImg.allocate(kinect.width, kinect.height);
    thImg.allocate(kinect.width, kinect.height);
    
    b1 = NULL;
    b2 = NULL;

    ship = s;
    math = m;
}

//--------------------------------------------------------------
void KinectController::update() {
    kinect.setCameraTiltAngle(angle);
    kinect.update();
    if(kinect.isFrameNew()) {
        setImages();
        contours.findContours(thImg, 250, 100000, 10, false, true);
            updateShip();
    }
}

//--------------------------------------------------------------
void KinectController::setImages() {
    clrImg.setFromPixels(kinect.getPixels(), kinect.width, kinect.height);
    depthImg.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
    register unsigned char *pixels = kinect.getDepthPixels();
    for(register int i=0;i<kinect.height*kinect.width;i++) {
        if (pixels[i]<farThreshold || pixels[i]>nearThreshold) {
            pixels[i] = 0;
        }
        else {
            pixels[i] = 255;
        }
    }
    thImg.setFromPixels(pixels, kinect.width, kinect.height);
}

//--------------------------------------------------------------
void KinectController::updateShip() {
    if(contours.blobs.size() == 2) {
        if(!trackingHands) {
            b1 = contours.blobs[0].centroid.x<=contours.blobs[1].centroid.x ? &(contours.blobs[0].centroid) : &(contours.blobs[1].centroid);
            b2 = contours.blobs[0].centroid.x>=contours.blobs[1].centroid.x ? &(contours.blobs[0].centroid) : &(contours.blobs[1].centroid);
        }
        float tan = (b2->y - b1->y)/(b2->x - b1->x);
        float arctan = math->arcTanLookup(tan);
        if(isLeft(b1,b2) && isAbove(b1,b2))
            arctan -= PI;
        else if(!isLeft(b1,b2) && isAbove(b1,b2))
            arctan = -arctan;
        else if(!isLeft(b1,b2) && !isAbove(b1,b2))
            arctan += TWO_PI;
        ship->setScaleSpeed((abs(b2->x-b1->x)+abs(b2->y-b1->y))/((kinect.width+kinect.height)*0.5));
        ship->setScaleRot(arctan/TWO_PI);
        trackingHands = true;
    }
    else {
        trackingHands = false;
    }
    
}

//--------------------------------------------------------------
void KinectController::draw() {
    int width = ofGetWidth()/5.25;
    int height = ofGetHeight()/5.25;
    ofPushStyle();
    ofPushMatrix();
        ofSetColor(200, 200, 200, 25);
        ofFill();
        ofRect(0, 10, ofGetWidth(), height+20);
        ofSetColor(255, 255, 255);
        string data = "NearThreshold: "+ofToString(nearThreshold)
                     +"\nFarThreshold: "+ofToString(farThreshold)
                     +"\nAngle: "+ofToString(angle)
                     +"\nBlobs: "+ofToString((int)contours.blobs.size());
        ofDrawBitmapString(data, 20, 50);
        ofTranslate(20+ofGetWidth()/5, 20);
        clrImg.draw(0, 0, width, height);
        depthImg.draw(width+10, 0, width, height);
        thImg.draw(2*width+20, 0, width, height);
        contours.draw(2*width+20, 0, width, height);
    ofPopMatrix();
    if(trackingHands) {
        ofSetColor(255, 0, 0);
        ofCircle(scaleFactor_w*b1->x, scaleFactor_h*b1->y, 15);
        ofCircle(scaleFactor_w*b2->x, scaleFactor_h*b2->y, 15);
        ofSetColor(200, 200, 255, 50);
        ofLine(scaleFactor_w*b1->x, scaleFactor_h*b1->y, scaleFactor_w*b2->x, scaleFactor_h*b2->y);
    }
    ofPopStyle();
}