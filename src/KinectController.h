#ifndef __TUNNEL_KINECT_CONTROLLER_INC
#define __TUNNEL_KINECT_CONTROLLER_INC

#include "ofAppRunner.h"
#include "ofGraphics.h"

#include "Ship.h"
#include "LookupMath.h"

class KinectController {
private:
    Ship *ship;
    LookupMath *math;
    
    int nearThreshold;
    int farThreshold;
public:
    ~KinectController();
    void initialize(Ship *s, LookupMath *m);
    void update();
    void draw();
    
    void incNearThreshold() {nearThreshold<=255?nearThreshold++:0;}
    void decNearThreshold() {nearThreshold>=0?nearThreshold--:0;}
    void incFarThreshold() {nearThreshold<=255?nearThreshold++:0;}
    void decFarThreshold() {nearThreshold>=0?nearThreshold--:0;}
};

#endif