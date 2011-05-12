#ifndef __TUNNEL_INC
#define __TUNNEL_INC

#include "ofGraphics.h"

#include "LookupMath.h"

#define DEPTH_OF_TUNNEL 8.5

class Tunnel {
private:
    int width;
    int height;
    float t;
    float z;
    LookupMath *m;
    
    ofPoint getPoint(float x, float y, float z);
    ofPoint getSurface(float a, float z);
    void drawQuad(float a, float da, float z, float dz);
    
    float max(float x, float y) {return x>y?x:y;}
    float abs(float x) {return x<0?-x:x;} 
    float sinLookup(float x);
    float cosLookup(float y);
    
public:
    void initialize(int w, int h, LookupMath *m);
    void draw(int speed);
};

#endif