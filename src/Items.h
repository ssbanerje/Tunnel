#ifndef __TUNNEL_ITEM_INC
#define __TUNNEL_ITEM_INC

#include "ofMain.h"

class Item {
private:
    float rad;
    float angle;
    float depth;
    int points;
public:
    void setRad(float r) {rad = r;}
    void setAngle(float a) {angle = a;}
    void setDepth(float d) {depth = d;}
    void setPts(int p) {points = p;}
    
    float getAngle() {return angle;}
    float getRad() {return rad;}
    float getDepth() {return depth;}
    int getPoints() {return points;}
    
    static void reapItem(Item* i);
    static void updateItem(Item* i);
};

#endif