#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "Application.h"

#define WIDTH 1024
#define HEIGHT 768

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, WIDTH, HEIGHT, OF_WINDOW);

	ofRunApp(new Application());
}
