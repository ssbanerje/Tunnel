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
    speed = 0.9*MIN_SPEED;
    rot = 0;
}

//--------------------------------------------------------------
void Application::draw() {
    tunnel.draw(speed);
    g.drawCrossHairs();
    
    //Draw Speed Bar
    ofPushMatrix();
        ofSetColor(255, 255, 255);
        ofSetColor(255,255,255);
        ofNoFill();
        ofTranslate(20, 10*HEIGHT/11);
        ofDrawBitmapString("Speed", 0, -5);
        ofBeginShape();
            ofVertex(0,0);
            ofVertex(0,HEIGHT/80);
            ofVertex(WIDTH/3, HEIGHT/80);
            ofVertex(WIDTH/3, 0);
            ofVertex(0, 0);
        ofEndShape();
        ofSetColor(55,100,200);
        ofFill();
        int m = WIDTH/3 - 4;
        ofBeginShape();
            ofVertex(3,3);
            ofVertex(3,HEIGHT/80-3);
            ofVertex((m-3)*(speed-MAX_SPEED)/(MAX_SPEED-MIN_SPEED)+m, HEIGHT/80-3);
            ofVertex((m-3)*(speed-MAX_SPEED)/(MAX_SPEED-MIN_SPEED)+m, 3);
            ofVertex(3, 3);
        ofEndShape();
    ofPopMatrix();
    
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
        case 'w':
        case 'W':
            speed>MAX_SPEED?speed-=10:0;
            break;
        case 's':
        case 'S':
            speed<0.9*MIN_SPEED?speed+=10:0;
            break;
        case 'a':
        case 'A':
            rot+=10;
            break;
        case 'd':
        case 'D':
            rot-=10;
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
