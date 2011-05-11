#ifndef __TUNNEL_HOOP_INC
#define __TUNNEL_HOOP_INC

#include "ofGraphics.h"

class Hoop {
    ofPoint pos;
    ofColor color;
    int score;
    
public:
    Hoop();
    void drawHoop();
    int getScore() {return score;}
};

#endif