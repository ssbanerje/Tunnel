#include "Application.h"

//--------------------------------------------------------------
void Application::setup() {
    ofSetLogLevel(0);
	ofLog(OF_LOG_VERBOSE, "Application::setup()");
    
    ofBackground(0,0,0);
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetFrameRate(30);
    ofSetWindowTitle("Tunnel");
    
    tunnel.initialize(WIDTH, HEIGHT, &m);    
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw();
    
    g.drawCrossHairs();
    
    ofSetColor(255, 255, 255);
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 100,500);
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
        case '+':
        case '=':
            g.incCHSize();
            break;
        case '_':
        case '-':
            g.decCHSize();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void Application::mouseMoved(int x, int y ) {
    g.setMousePos(x,y);
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
