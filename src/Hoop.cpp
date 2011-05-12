#include "Hoop.h"

//--------------------------------------------------------------
Hoop::Hoop() {    
    color.r = 255*ofRandomf();
    color.g = 255*ofRandomf();
    color.b = 255*ofRandomf();
    color.a = 255*ofRandomf();
    
    pos.set(WIDTH/2 + (ofRandomf()-0.5)*707, HEIGHT/2 + (ofRandomf()-0.5)*707, 0);
}

//--------------------------------------------------------------
void Hoop::drawHoop() {
    ofSetColor(color.r, color.g, color.b, color.a);
    ofPushStyle();
        ofNoFill();
        ofSetLineWidth(3);
        ofCircle(pos.x, pos.y, 1/pos.z*10);
    ofPopStyle();
}