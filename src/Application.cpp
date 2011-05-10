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
    //Draw tunnel
    ofPushMatrix();
        ofTranslate(WIDTH/2, HEIGHT/2);
        ofRotateZ(rot);
        ofTranslate(-WIDTH/2, -HEIGHT/2);
        tunnel.draw(speed);
    ofPopMatrix();
    
    drawControlPanel();
    
    //Draw FPS
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
            rot-=5;
            break;
        case 'd':
        case 'D':
            rot+=5;
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

//--------------------------------------------------------------
void Application::drawControlPanel() {
    ofPushStyle();
        ofSetColor(200, 200, 200, 25);
        ofFill();
        ofRect(0, 5*HEIGHT/6, WIDTH, HEIGHT/8);
    ofPopStyle();
    
    ofPushMatrix();
    ofPushStyle();
        ofSetColor(255, 255, 255);
        ofNoFill();
        ofTranslate(20, 9*HEIGHT/10);
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
    ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
        ofSetColor(255, 255, 255);
        ofTranslate(10*WIDTH/11, 9*HEIGHT/10);
        ofDrawBitmapString("Rotation", -30, -27);
        ofNoFill();
        ofCircle(0, 0, 20);
        ofLine(20, 0, -20, 0);
        ofLine(0, 20, 0, -20);
        ofSetColor(55, 100, 200);
        ofRotateZ(rot);
        ofSetLineWidth(3);
        ofLine(0, -25, 0, 25);
        ofSetLineWidth(1);
    ofPopStyle();
    ofPopMatrix();
}
