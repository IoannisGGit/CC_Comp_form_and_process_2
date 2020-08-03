#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	setupWorld("Assignment 1", 1000, 1000, 60, ofColor::black, true);
	
	myParticleSystem.setup();
	setupGui();
	setupCamera();
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	myParticleSystem.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);
	gui.draw();
	myCamera.begin();
	myParticleSystem.draw();
	myCamera.end();
}


void ofApp::setupWorld(string _windowName, int _windowWidth, int _windowHeight, int _frameRate, ofColor _background, bool _fullscreen) {
	ofSetWindowTitle(_windowName);
	ofSetWindowShape(_windowWidth, _windowHeight);
	ofSetFullscreen(_fullscreen);
	ofSetFrameRate(_frameRate);
	ofBackground(_background);
}

void ofApp::setupGui() {
	gui.setup("Parameters");
	gui.add(myParticleSystem.ps_parameters);
}

void ofApp::setupCamera() {
	myCamera.setAutoDistance(false);
	myCamera.setPosition(vec3(0.0f, 10.0f, -100.f));
	myCamera.setTarget(vec3(0.0f, 0.0f, 0.0f));
}



