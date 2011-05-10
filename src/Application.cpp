#include "Application.h"

//--------------------------------------------------------------
Application::~Application() {
	ofLog(OF_LOG_VERBOSE, "Application::~Application()");
}

//--------------------------------------------------------------
void Application::setup() {
    ofSetLogLevel(0);
	ofLog(OF_LOG_VERBOSE, "Application::setup()");
    
    ofBackground(50, 50, 50);
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetFrameRate(25);
    ofSetWindowTitle("Tunnel");
    
    tunnel.setWindowDimensions(WIDTH,HEIGHT);    
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw();
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
