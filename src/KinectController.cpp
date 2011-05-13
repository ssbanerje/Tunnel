#include "KinectController.h"

//--------------------------------------------------------------
KinectController::KinectController() {
    ofLog(OF_LOG_VERBOSE, "KinectController::KinectController()");
    angle = 0;
    kinect.init();
    kinect.open();
    kinect.setCameraTiltAngle(angle);
    
    nearThreshold = 255;
    farThreshold = 100;
    
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
void KinectController::updateShip() {
    
}

//--------------------------------------------------------------
void KinectController::draw() {
    ofPushStyle();
    ofPushMatrix();
        ofSetColor(200, 200, 200, 25);
        ofFill();
        ofRect(0, 10, ofGetWidth(), 240+20);
        ofSetColor(255, 255, 255);
        string data = "NT: "+ofToString(nearThreshold)+"\nFT: "+ofToString(farThreshold)+"\nANGLE: "+ofToString(angle);
        ofDrawBitmapString(data, 20, 50);
        ofTranslate(20+ofGetWidth()/5, 20);
        clrImg.draw(0, 0, 320, 240);
        depthImg.draw(330, 0, 320, 240);
        thImg.draw(660, 0, 320, 240);
        contours.draw(660, 0, 320, 240);
    ofPopMatrix();
    ofPopStyle();
}