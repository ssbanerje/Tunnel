#include "Application.h"

//--------------------------------------------------------------
Application::~Application() {
	ofLog(OF_LOG_VERBOSE, "Application::~Application()");
}

//--------------------------------------------------------------
void Application::setup() {
    ofSetLogLevel(0);
	ofLog(OF_LOG_VERBOSE, "Application::setup()");
    
    ofBackground(0,0,0);
    ofSetColor(255,255,255);
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetFrameRate(21);
    ofEnableSmoothing();
    ofSetWindowTitle("Tunnel");
    
    tunnel.initialize(WIDTH, HEIGHT);    
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw();
    ofSetColor(255,255,255);
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
