#include "Ship.h"

Ship::Ship() {
    ofLog(OF_LOG_VERBOSE, "Gun::Gun()");
    mouseSize = 3;
    speed = 0.9*MIN_SPEED;
    model.loadModel("fighter1.3ds");
}

//--------------------------------------------------------------
void Ship::drawCrossHairs() {
    ofSetColor(255,0,0);
    ofCircle(mousePos.x, mousePos.y, mouseSize*3);
    ofCircle(mousePos.x, mousePos.y, mouseSize);
    int x = mouseSize*4;
    ofLine(mousePos.x-x, mousePos.y, mousePos.x+x, mousePos.y);
    ofLine(mousePos.x, mousePos.y-x, mousePos.x, mousePos.y+x);
}

//--------------------------------------------------------------
void Ship::drawShip() {
    
    ofPushMatrix();
        ofTranslate(400, 400);
        ofRotate(90, 0, -1, 0); 
        ofRotate(180, 0, 0, -1);
        glScalef(10, 10, 10);
        model.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void Ship::drawControlPanel() {
    ofEnableSmoothing();
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
    ofDisableSmoothing();
}