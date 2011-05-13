#include "Ship.h"

GLfloat lightOnePosition[] = {0,0,0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

//--------------------------------------------------------------
void Ship::initialize(LookupMath *m) {
    ofLog(OF_LOG_VERBOSE, "Ship::initialize()");
    
    this->m = m;
    speed = 0.9*MIN_SPEED;
    rot = 0;
    score = 0;
    model.loadModel("fighter1.3ds");
    font.loadFont("Courier New.ttf",20,true,true);
    font.setLineHeight(20);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightOneColor);
    glLightfv(GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightTwoColor);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glColorMaterial (GL_FRONT, GL_AMBIENT);
}

//--------------------------------------------------------------
void Ship::drawShip() {
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    ofPushMatrix();
    ofPushStyle();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotate(90, 0, -1, 0); 
        ofRotate(180, 0, 0, -1);
        ofRotate(180, 0, 0, 1);
        glTranslatef(0, speed*m->cosLookup(TWO_PI*rot/360)*5, speed*m->sinLookup(TWO_PI*rot/360)*5);
        ofRotate(rot, 1, 0, 0);
        glScalef(10, -10, 10);
        model.draw();
    ofPopStyle();
    ofPopMatrix();
    
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
}

//--------------------------------------------------------------
void Ship::drawControlPanel() {
    ofEnableSmoothing();
    ofPushStyle();
        ofSetColor(200, 200, 200, 25);
        ofFill();
        ofRect(0, 5*ofGetHeight()/6, ofGetWidth(), ofGetHeight()/8);
    ofPopStyle();
    
    ofPushMatrix();
    ofPushStyle();
        ofSetColor(255, 255, 255);
        ofNoFill();
        ofTranslate(20, 9*ofGetHeight()/10);
        ofDrawBitmapString("Speed", 0, -5);
        ofBeginShape();
        ofVertex(0,0);
        ofVertex(0,ofGetHeight()/80);
        ofVertex(ofGetWidth()/3, ofGetHeight()/80);
        ofVertex(ofGetWidth()/3, 0);
        ofVertex(0, 0);
        ofEndShape();
        ofSetColor(55,100,200);
        ofFill();
        int m = ofGetWidth()/3 - 4;
        ofBeginShape();
        ofVertex(3,3);
        ofVertex(3,ofGetHeight()/80-3);
        ofVertex((m-3)*(speed-MAX_SPEED)/(MAX_SPEED-MIN_SPEED)+m, ofGetHeight()/80-3);
        ofVertex((m-3)*(speed-MAX_SPEED)/(MAX_SPEED-MIN_SPEED)+m, 3);
        ofVertex(3, 3);
        ofEndShape();
    ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
        ofSetColor(255, 255, 255);
        ofTranslate(10*ofGetWidth()/11, 9*ofGetHeight()/10);
        ofDrawBitmapString("Rotation", -30, -27);
        ofNoFill();
        ofCircle(0, 0, 20);
        ofLine(20, 0, -20, 0);
        ofLine(0, 20, 0, -20);
        ofSetColor(55, 100, 200);
        ofRotateZ(rot);
        ofSetLineWidth(3);
        ofLine(0, 0, 0, -25);
        ofLine(-25, 0, 25, 0);
        ofSetLineWidth(1);
    ofPopStyle();
    ofPopMatrix();

    ofSetColor(255, 255, 255);
    font.drawString("Score: "+ofToString(score), ofGetWidth()/2, 6.3*ofGetHeight()/7);
    
    ofDisableSmoothing();
}