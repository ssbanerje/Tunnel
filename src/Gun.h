#ifndef __TUNNEL_GUN_INC
#define __TUNNEL_GUN_INC

#include "ofMain.h"

class Gun {
private:
    ofPoint mousePos;
    int mouseSize;
public:
    Gun();
    void setMousePos(int x,int y) {mousePos.set(x,y,0);}
    void incCHSize() {mouseSize<15?mouseSize++:1;}
    void decCHSize() {mouseSize>2?mouseSize--:1;}
    void drawCrossHairs();
};

#endif