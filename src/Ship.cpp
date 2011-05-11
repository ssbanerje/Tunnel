#include "Ship.h"

GLfloat lightOnePosition[] = {0,0,0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {WIDTH,HEIGHT,0};

void Ship::initialize(Math *m) {
    ofLog(OF_LOG_VERBOSE, "Ship::initialize()");
    mouseSize = 3;
    targeting = false;
    this->m = m;
    
    speed = 0.9*MIN_SPEED;
    rot = 0;
    
    model.loadModel("fighter1.3ds");
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightOneColor);
    glLightfv(GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightTwoColor);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glColorMaterial (GL_FRONT, GL_AMBIENT);
}

//--------------------------------------------------------------
void Ship::drawCrossHairs() {
    if((mousePos.x-WIDTH/2)*(mousePos.x-WIDTH/2) + (mousePos.y-HEIGHT/2)*(mousePos.y-HEIGHT/2) < 1.0/speed*1e5) {
        ofSetColor(255,0,0);
        targeting = true;
    }
    else {
        ofSetColor(255, 255, 0);
        targeting = true;
    }
    ofCircle(mousePos.x, mousePos.y, mouseSize*3);
    ofCircle(mousePos.x, mousePos.y, mouseSize);
    int x = mouseSize*4;
    ofLine(mousePos.x-x, mousePos.y, mousePos.x+x, mousePos.y);
    ofLine(mousePos.x, mousePos.y-x, mousePos.x, mousePos.y+x);
}

//--------------------------------------------------------------
void Ship::drawShip() {
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    ofPushMatrix();
    ofPushStyle();
        ofTranslate(WIDTH/2, HEIGHT/2);
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
        ofLine(-25, 0, 25, 0);
        ofSetLineWidth(1);
    ofPopStyle();
    ofPopMatrix();
    ofDisableSmoothing();
}