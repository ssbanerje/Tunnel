#ifndef __TUNNEL_GUN_INC
#define __TUNNEL_GUN_INC

#include "ofGraphics.h"
#include "ofx3DModelLoader.h"

#include "ScreenDims.h"
#include "Math.h"

#define MAX_SPEED 10
#define MIN_SPEED 100

class Ship {
private:
    int speed;
    int rot;
    int score;
    
    ofx3DModelLoader model;
    Math *m;
    
public:
    void incSpeed() {speed>MAX_SPEED?speed-=5:0;}
    void decSpeed() {speed<0.9*MIN_SPEED?speed+=5:0;}
    void incRot() {rot+=5;}
    void decRot() {rot-=5;}
    int getSpeed() {return speed;}
    int getRot() {return rot;}
    
    void initialize(Math *m);
    void drawCrossHairs();
    void drawShip();
    void drawControlPanel();
};

#endif