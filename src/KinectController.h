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
    
    int nearThreshold;
    int farThreshold;
    float angle;
    ofxKinect kinect;
    
    ofxCvColorImage clrImg;
    ofxCvGrayscaleImage depthImg;
    ofxCvGrayscaleImage thImg;
    ofxCvContourFinder contours;
    
    void setImages();
    void updateShip();
    
public:
    KinectController();
    ~KinectController();
    void initialize(Ship *s, LookupMath *m);
    void update();
    void draw();
    
    void incNearThreshold() {nearThreshold<=255?nearThreshold++:0;}
    void decNearThreshold() {nearThreshold>=0?nearThreshold--:0;}
    void incFarThreshold() {nearThreshold<=255?nearThreshold++:0;}
    void decFarThreshold() {nearThreshold>=0?nearThreshold--:0;}
    void incAngle() {angle<30.0?angle++:0;}
    void decAngle() {angle>-30.0?angle--:0;}
};

#endif