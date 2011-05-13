#ifndef __TUNNEL_KINECT_CONTROLLER_INC
#define __TUNNEL_KINECT_CONTROLLER_INC

#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

#include "Ship.h"
#include "LookupMath.h"

class KinectController {
private:
    Ship *ship;
    LookupMath *math;
    ofPoint *b1,*b2;
    
    int nearThreshold;
    int farThreshold;
    float angle;
    float scaleFactor_w;
    float scaleFactor_h;
    bool trackingHands;
    ofxKinect kinect;
    
    ofxCvColorImage clrImg;
    ofxCvGrayscaleImage depthImg;
    ofxCvGrayscaleImage thImg;
    ofxCvContourFinder contours;
    
    void setImages();
    void updateShip();
    
public:
    ~KinectController();
    void initialize(Ship *s, LookupMath *m);
    void update();
    void draw();
    
    void incNearThreshold() {nearThreshold<=255?nearThreshold+=5:0;}
    void decNearThreshold() {nearThreshold>=0?nearThreshold-=5:0;}
    void incFarThreshold() {farThreshold<=255?farThreshold+=5:0;}
    void decFarThreshold() {farThreshold>=0?farThreshold-=5:0;}
    void incAngle() {angle<30.0?angle+=5:0;}
    void decAngle() {angle>-30.0?angle-=5:0;}
};

#endif