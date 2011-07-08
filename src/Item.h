#ifndef __TUNNEL_ITEM_INC
#define __TUNNEL_ITEM_INC

#include "ofMain.h"
#include "LookupMath.h"
#include "Ship.h"
#include "Tunnel.h"

class Item {
private:
    float rad;
    float angle;
    float depth;
    
    int points;
    ofColor col;
    
    LookupMath *math;
    
public:
    void initialize(LookupMath *m);
    void draw();
    void updateItem();
    
    void setRad(float r) {rad = r;}
    void setAngle(float a) {angle = a;}
    void setDepth(float d) {depth = d;}
    void setPts(int p) {points = p;}
    
    float getAngle() {return angle;}
    float getRad() {return rad;}
    float getDepth() {return depth;}
    int getPoints() {return points;}
    
    static bool reapItem(Item* i);
};

#endif