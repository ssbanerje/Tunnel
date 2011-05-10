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
    
public:
    Tunnel() {}
    ~Tunnel() {}
    void setWindowDimensions(int w, int h);
    void draw();
};

#endif