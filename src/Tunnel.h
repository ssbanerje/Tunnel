#ifndef __TUNNEL_INC
#define __TUNNEL_INC

#include "ofMain.h"
#include <math.h>

class Tunnel {
private:
    int width;
    int height;
    float t;
    float z;
    
    ofPoint getPoint(float x, float y, float z);
    ofPoint getSurface(float a, float z);
    void drawQuad(float a, float da, float z, float dz);
    
    float max(float x, float y) {return x>y?x:y;}
    float abs(float x) {return x<0?-x:x;} 
    
public:
    Tunnel() {}
    ~Tunnel() {}
    void initialize(int w, int h);
    void draw();
};

#endif