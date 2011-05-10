#include "Gun.h"

//--------------------------------------------------------------
void Gun::drawCrossHairs() {
    ofSetColor(255,0,0);
    ofCircle(mousePos.x, mousePos.y, mouseSize*3);
    ofCircle(mousePos.x, mousePos.y, mouseSize);
    int x = mouseSize*4;
    ofLine(mousePos.x-x, mousePos.y, mousePos.x+x, mousePos.y);
    ofLine(mousePos.x, mousePos.y-x, mousePos.x, mousePos.y+x);
}