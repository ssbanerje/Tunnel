#include "Application.h"

//--------------------------------------------------------------
Application::~Application() {
	ofLog(OF_LOG_VERBOSE, "Application::~Application()");
    delete tunnel;
}

//--------------------------------------------------------------
void Application::setup() {
    ofSetLogLevel(0);
	ofLog(OF_LOG_VERBOSE, "Application::setup()");
    
    ofBackground(50, 50, 50);
    ofSetWindowShape(800, 600);
    ofSetWindowTitle("Tunnel");
    
    tunnel = new Tunnel();    
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel->draw();
}

//--------------------------------------------------------------
void Application::update() {
    tunnel->updateStructure();    
}
//--------------------------------------------------------------
void Application::exit() {
    
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
