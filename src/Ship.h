#ifndef __TUNNEL_GUN_INC
#define __TUNNEL_GUN_INC

#include "ofMain.h"
#include "ofx3DModelLoader.h"

#include "ScreenDims.h"

#define MAX_SPEED 10
#define MIN_SPEED 100

class Ship {
private:
    ofPoint mousePos;
    int mouseSize;
    int speed;
    int rot;
    ofx3DModelLoader model;
    
public:
    Ship();
    
    void setMousePos(int x,int y) {mousePos.set(x,y,0);}
    void incCHSize() {mouseSize<15?mouseSize++:1;}
    void decCHSize() {mouseSize>2?mouseSize--:1;}
    void incSpeed() {speed>MAX_SPEED?speed-=10:0;}
    void decSpeed() {speed<0.9*MIN_SPEED?speed+=10:0;}
    void incRot() {rot+=5;}
    void decRot() {rot-=5;}
    int getRot() {return rot;}
    int getSpeed() {return speed;}
    int getMaxSpeed() {return MAX_SPEED;}
    int getMinSpeed() {return MIN_SPEED;}
    
    void drawCrossHairs();
    void drawShip();
    void drawControlPanel();
};

#endif