#include "Application.h"

//--------------------------------------------------------------
void Application::setup() {
    ofSetLogLevel(0);
	ofLog(OF_LOG_VERBOSE, "Application::setup()");
    
    ofBackground(0, 0, 0);
    ofSetWindowShape(ofGetWidth(), ofGetHeight());
    ofSetWindowPosition(10, 10);
    ofSetFrameRate(30);
    ofSetWindowTitle("Tunnel");
    
    ofSeedRandom();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofHideCursor();
    
    glLoadIdentity();
    
    tunnel.initialize(ofGetWidth(), ofGetHeight(), &m);
    ship.initialize(&m);
    kinect.initialize(&ship,&m);
    showKinectMenu = true;
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw(ship.getSpeed());
    
    ship.drawShip();
    
    ship.drawControlPanel();
    
    if (showKinectMenu) {
        kinect.draw();
    }
    
    //Draw FPS
    ofSetColor(255, 255, 255);
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 100, ofGetHeight()-20);
}

//--------------------------------------------------------------
void Application::update() {
    kinect.update();
}

//--------------------------------------------------------------
void Application::exit() {
    ofLog(OF_LOG_VERBOSE, "Application::exit()");
}

//--------------------------------------------------------------
void Application::keyPressed(int key) {
    switch (key) {
#ifndef GAME
        case 'f':
        case 'F':
            ofToggleFullscreen();
            tunnel.initialize(ofGetWidth(), ofGetHeight(), &m);
            break;
#endif
        case 'w':
        case 'W':
        case OF_KEY_UP:
            ship.incSpeed();
            break;
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            ship.decSpeed();
            break;
        case 'a':
        case 'A':
        case OF_KEY_LEFT:
            ship.incRot();
            break;
        case 'd':
        case 'D':
        case OF_KEY_RIGHT:
            ship.decRot();
            break;
        case 'n':
            kinect.decNearThreshold();
            break;
        case 'N':
            kinect.incNearThreshold();
            break;
        case 'm':
            kinect.decFarThreshold();
            break;
        case 'M':
            kinect.incFarThreshold();
            break;
        case ',':
            kinect.decAngle();
            break;
        case '<':
            kinect.incAngle();
            break;
        case 'k':
        case 'K':
            showKinectMenu = !showKinectMenu;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void Application::mouseMoved(int x, int y ) {
}

//--------------------------------------------------------------
void Application::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void Application::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void Application::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void Application::windowResized(int w, int h) {
}
