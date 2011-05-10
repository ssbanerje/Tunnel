#ifndef __TUNNEL_APPLICATION_INC
#define __TUNNEL_APPLICATION_INC

#include "ofMain.h"
#include "Tunnel.h"
#include "Gun.h"
#include "Math.h"

#define WIDTH 1024
#define HEIGHT 768

#define MAX_SPEED 10
#define MIN_SPEED 100

class Application : public ofBaseApp{
public:
    void setup();
	void draw();
	void update();
	void exit();
	void keyPressed(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x,int y,int button);
	void mousePressed(int x,int y,int button);
	void mouseReleased(int x,int y,int button);
	void windowResized(int w,int h);
    void drawControlPanel();
    
private:
    Math m;
    Tunnel tunnel;
    Gun g;
    
    int speed;
    int rot;
};

#endif
