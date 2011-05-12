#ifndef __TUNNEL_HOOP_INC
#define __TUNNEL_HOOP_INC

#include "ofGraphics.h"
#include "ofMath.h"

#include "ScreenDims.h"

class Hoop {
private:
    ofPoint pos;
    ofColor color;
    int score;
    
public:
    Hoop();
    void drawHoop();
    int getScore() {return score;}
};

#endif