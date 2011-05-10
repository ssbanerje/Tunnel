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
    speed = 100;
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw(speed);
    
    g.drawCrossHairs();
    
    ofSetColor(255, 255, 255);
    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(fpsStr, 100,500);
    fpsStr = "speed: "+ofToString(speed, 2);
    ofDrawBitmapString(fpsStr, 100,600);
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
        case 'w':
        case 'W':
            speed>10?speed-=10:0;
            break;
        case 's':
        case 'S':
            speed<100?speed+=10:0;
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
    g.setMousePos(x,y);
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
