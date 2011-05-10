#include "Tunnel.h"

//--------------------------------------------------------------
void Tunnel::initialize(int w, int h) {
    ofLog(OF_LOG_VERBOSE, "Tunnel::initialize(%d, %d)",w,h);
    width = w;
    height = h;
    t = 0;
    z = -0.2;
    for (register int i=0; i<ARR_LEN; i++) {
        sinArr[i] = sinf(TWO_PI/ARR_LEN * i);
        cosArr[i] = cosf(TWO_PI/ARR_LEN * i);
    }
}

//--------------------------------------------------------------
ofPoint Tunnel::getPoint(float x, float y, float z) {
    ofPoint p;
    p.set(x,y,z);
    return p;
}

//--------------------------------------------------------------
ofPoint Tunnel::getSurface(float a, float z) {
    register float r = width/10.0;
	register float R = width/3.0;
	register float b = -20*cosLookup(a*5 + t);
	return getPoint(
             width/2 + (R * cosLookup(a) + r*sinLookup(z + 2*t))/z + cosLookup(a)*b, 
             height/2 + (R * sinLookup(a))/z + sinLookup(a)*b,
             z);
}

//--------------------------------------------------------------
void Tunnel::drawQuad(float a, float da, float z, float dz) {
    ofPoint v[4] = {getSurface(a, z), getSurface(a+da, z),
        getSurface(a+da, z+dz), getSurface(a, z+dz)};
    ofFill();
    ofBeginShape();
        ofVertex(v[0].x, v[0].y);
        ofVertex(v[1].x, v[1].y);
        ofVertex(v[2].x, v[2].y);
        ofVertex(v[3].x, v[3].y);
    ofEndShape();
    ofNoFill();
    ofSetColor(100,100,255,50);
    ofBeginShape();
        ofVertex(v[0].x, v[0].y);
        ofVertex(v[1].x, v[1].y);
        ofVertex(v[2].x, v[2].y);
        ofVertex(v[3].x, v[3].y);
    ofEndShape();
}

//--------------------------------------------------------------
void Tunnel::draw() {
    t += 1/30.0;
    ofSetColor(255,0,0);
    float a,da,dz,fog,k;
    int n;
    n = 30;
    a = 0;
    da = TWO_PI/n;
    dz = 0.25;
    int *x = (int*)&k;
    for (register float zz=z+DEPTH_OF_TUNNEL; zz>z; zz-=dz) {
        for (register int i=0; i<n; i++) {
            fog = 1/max((zz+0.7)-3,1);
            if (zz <= 2) 
                fog = max(0, (zz*zz)/4);
            k = (205*(fog*abs( sinLookup(i/n*2*PI+t) )));
            *x >>= 0;
            k *= (0.55+0.45*cosLookup((i/n+0.25)*PI*5));
            *x >>= 0;
            ofSetColor(k, k, k);
            drawQuad(a, da, zz, dz);
            if(i%3==0) {
                ofSetColor(255, 200, 255);
                drawQuad(a, da/10, zz, dz);
                drawQuad(a, da, zz, dz/10);

            }
            a += da;
        }
    }
    z -= 0.05;
    if(z <= dz)
        z += dz;
}

//--------------------------------------------------------------
float Tunnel::sinLookup(float x) {
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return sinArr[(int)(x/TWO_PI*ARR_LEN)];
}

//--------------------------------------------------------------
float Tunnel::cosLookup(float x) {
    int r = (int) (x/TWO_PI);
    x -= r*TWO_PI;
    return cosArr[(int)(x/TWO_PI*ARR_LEN)];
}