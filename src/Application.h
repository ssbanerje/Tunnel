#ifndef __TUNNEL_APPLICATION_INC
#define __TUNNEL_APPLICATION_INC

#include "ofMain.h"
#include "Tunnel.h"

#define WIDTH 1024
#define HEIGHT 768

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
    
private:
    Tunnel tunnel;
};

#endif
