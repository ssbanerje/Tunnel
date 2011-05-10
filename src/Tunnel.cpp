#include "Tunnel.h"

//--------------------------------------------------------------
void Tunnel::setWindowDimensions(int w, int h) {
    width = w;
    height = h;
    t = 0;
    z = -0.2;
}

//--------------------------------------------------------------
ofPoint Tunnel::getPoint(float x, float y, float z) {
    ofPoint p;
    p.set(x,y,z);
    return p;
}

//--------------------------------------------------------------
ofPoint Tunnel::getSurface(float a, float z) {
    float r = width/10.0;
	float R = width/3.0;
	float b = -20*cos(a*5 + t);
	return getPoint(
             width/2 + (R * cos(a) + r*sin(z + 2*t))/z + cos(a)*b, 
             height/2 + (R * sin(a))/z + sin(a)*b,
             z
             );
}

//--------------------------------------------------------------
void Tunnel::drawQuad(float a, float da, float z, float dz) {
    
}

//--------------------------------------------------------------
void Tunnel::draw() {
    
}
