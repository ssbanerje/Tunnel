#include "KinectController.h"

//--------------------------------------------------------------
KinectController::KinectController() {
    ofLog(OF_LOG_VERBOSE, "KinectController::KinectController()");
    angle = 0;
    kinect.init();
    kinect.open();
    kinect.setCameraTiltAngle(angle);
    
    nearThreshold = 200;
    farThreshold = 150;
    
    clrImg.allocate(kinect.width, kinect.height);
    depthImg.allocate(kinect.width, kinect.height);
    thImg.allocate(kinect.width, kinect.height);
}

//--------------------------------------------------------------
KinectController::~KinectController() {
    ofLog(OF_LOG_VERBOSE, "KinectController::~KinectController()");
    kinect.setCameraTiltAngle(0);
	kinect.close();
}

//--------------------------------------------------------------
void KinectController::initialize(Ship *s, LookupMath *m) {
    ship = s;
    math = m;
}

//--------------------------------------------------------------
void KinectController::update() {
    kinect.setCameraTiltAngle(angle);
    kinect.update();
    if(kinect.isFrameNew()) {
        setImages();
        contours.findContours(thImg, 250, 10000000, 10, false, true);
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
    }
    thImg.setFromPixels(pixels, kinect.width, kinect.height);
}

//--------------------------------------------------------------
void scalePoints(ofPoint *p, float scaleX, float scaleY, float scaleZ) {
    p->x *= scaleX;
    p->y *= scaleY;
    p->z *= scaleZ;
}

//--------------------------------------------------------------
float tanAnglePoints(const ofPoint *p1, const ofPoint *p2) {
    return (p2->y - p1->y)/(p2->x - p1->x);
}

//--------------------------------------------------------------
void KinectController::updateShip() {
    if(contours.blobs.size() == 2) {
        ofPoint *b1,*b2;
        float scaleFactor_w = ofGetWidth()/kinect.width;
        float scaleFactor_h = ofGetHeight()/kinect.height;
        float tanAngle = 0;
        b1 = contours.blobs[0].centroid.x<=contours.blobs[1].centroid.x ? &(contours.blobs[0].centroid) : &(contours.blobs[1].centroid);
        b2 = contours.blobs[0].centroid.x>=contours.blobs[1].centroid.x ? &(contours.blobs[0].centroid) : &(contours.blobs[1].centroid);
        float ht = (b1->y+b2->y)/2;
        scalePoints(b1, scaleFactor_w, scaleFactor_h, 0);
        scalePoints(b2, scaleFactor_w, scaleFactor_h, 0);
        tanAngle = tanAnglePoints(b1,b2);
        if(tanAngle>0.577) // 30 deg
            ship->incRot();
        else if(tanAngle<-0.577)
            ship->decRot();
        if(ht<ofGetHeight()/3)
            ship->incSpeed();
        else if(ht>2*ofGetHeight()/3)
            ship->decSpeed();            
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
    ofPopStyle();
}