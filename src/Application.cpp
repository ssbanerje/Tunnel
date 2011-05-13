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
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw(ship.getSpeed());
    
    ship.drawShip();
    
    ship.drawControlPanel();
    
    //Draw FPS
    ofSetColor(255, 255, 255);
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 100, ofGetHeight()-20);
}

//--------------------------------------------------------------
void Application::update() {
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
