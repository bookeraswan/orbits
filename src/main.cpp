#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main(int argsc, char** argsv){
	ofSetupOpenGL(1024, 768, OF_FULLSCREEN);		// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofApp* app = new ofApp();
	if(argsc > 1){
		app->setFile(argsv[1]);
	}
	ofRunApp(app);

}
