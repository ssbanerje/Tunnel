#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "Application.h"
#include "GameMode.h"


//========================================================================
int main() {
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, WIDTH, HEIGHT, WINDOW_MODE);
	ofRunApp(new Application());
}
