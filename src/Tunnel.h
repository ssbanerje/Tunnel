#ifndef __TUNNEL_INC
#define __TUNNEL_INC

#include "ofMain.h"
#include <math.h>

#define ARR_LEN 1000

class Tunnel {
private:
    int width;
    int height;
    float t;
    float z;
    float sinArr[ARR_LEN];
    float cosArr[ARR_LEN];
    
    ofPoint getPoint(float x, float y, float z);
    ofPoint getSurface(float a, float z);
    void drawQuad(float a, float da, float z, float dz);
    
    float max(float x, float y) {return x>y?x:y;}
    float abs(float x) {return x<0?-x:x;} 
    float sinLookup(float x);
    float cosLookup(float y);
    
public:
    Tunnel() {}
    ~Tunnel() {}
    void initialize(int w, int h);
    void draw();
};

#endif