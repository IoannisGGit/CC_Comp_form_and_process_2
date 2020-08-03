#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ParticleSystem.h"
using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		ParticleSystem myParticleSystem;
		ofEasyCam myCamera;

		ofxPanel gui;
		bool show_gui = true;

private:
	void setupWorld(string _windowName, int _windowWidth, int _windowHeight, int _frameRate, ofColor _background, bool _fullscreen);
	void setupCamera();
	void setupGui();
};
