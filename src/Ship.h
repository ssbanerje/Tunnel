#ifndef __TUNNEL_GUN_INC
#define __TUNNEL_GUN_INC

#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "ofx3DModelLoader.h"

#include "LookupMath.h"

#define MAX_SPEED 10
#define MIN_SPEED 100

class Ship {
private:
    int speed;
    int rot;
    int score;
    
    ofx3DModelLoader model;
    LookupMath *m;
    
    ofTrueTypeFont font;
    
public:
    void incSpeed() {speed>MAX_SPEED?speed-=5:0;}
    void decSpeed() {speed<0.9*MIN_SPEED?speed+=5:0;}
    void incRot() {rot+=5;}
    void decRot() {rot-=5;}
    int getSpeed() {return speed;}
    int getRot() {return rot;}
    
    void initialize(LookupMath *m);
    void drawCrossHairs();
    void drawShip();
    void drawControlPanel();
};

#endif