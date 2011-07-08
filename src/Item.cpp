#include "Item.h"

#define RANDOM ofRandom(0,1)

//--------------------------------------------------------------
void Item::initialize(LookupMath *m) {
    math = m;
    rad = (MIN_SPEED-MAX_SPEED)*RANDOM;
    angle = TWO_PI*RANDOM;
    points = 10*RANDOM;
    depth = DEPTH_OF_TUNNEL;
}

//--------------------------------------------------------------
bool Item::reapItem(Item *i) {
    return false;
}

//--------------------------------------------------------------
void Item::updateItem() {
    
}

//--------------------------------------------------------------
void Item::draw() {
    ofEnableSmoothing();
    ofPushMatrix();
    ofPushStyle();
        ofNoFill();
        ofSetLineWidth(4);
        ofSetColor(255, 255, 255);
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofTranslate(rad*math->cosLookup(angle)*5, rad*math->sinLookup(angle)*5);
        ofCircle(0, 0, 15);
    ofPopStyle();
    ofPopMatrix();
    ofDisableSmoothing();
}