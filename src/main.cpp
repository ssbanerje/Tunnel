#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "Application.h"
#include "ScreenDims.h"

int WIDTH = 1024;
int HEIGHT = 768;

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, WIDTH, HEIGHT, OF_WINDOW);

	ofRunApp(new Application());
}
