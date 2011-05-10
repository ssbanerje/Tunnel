#ifndef __TUNNEL_APPLICATION
#define __TUNNEL_APPLICATION

#include "ofMain.h"
#include "Tunnel.h"

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
    
    Application() {};
    ~Application();
    
private:
    Tunnel *tunnel;
};

#endif
