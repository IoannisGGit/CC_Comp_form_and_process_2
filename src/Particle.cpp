#include "Particle.h"
#include "helpers.h"

void Particle::setup(vec3 initPos) {
	myPos = initPos;
	myVel = vec3(0);
	mySize = 0.1f;
	myColor = ofColor::white;
	myAmp = 5.0f;
	myNoiseBias = 0.5f;
	myNoiseGain = 0.5f;
	myFreq = 2.0f;
}

void Particle::update() {
	float t = ofGetElapsedTimef();
	float myNoise = ofNoise(0.1f * myPos.x, 0.1f * myPos.z) * 1;
	myNoise = bias(myNoise, myNoiseBias);
	myNoise = gain(myNoise, myNoiseGain);
	myPos.y = myAmp * myNoise * sin(myFreq * ofGetElapsedTimef());
	//myPos.y = 5.0f * sin(10.0f * myPos.x) * sin(myPos.x + 2.0f * myPos.z + 2.0f * ofGetElapsedTimef());
	//myPos.y = myAmp * ofNoise(0.1f * myPos.x, 0.1f * myPos.z) * sin(2.0f * ofGetElapsedTimef());
	//myPos.y = myAmp * fourier(t+myPos.x + myPos.z, 5);
	//myPos.y = myAmp * ofNoise(0.1f * myPos.x, 0.1f * myPos.z) * fourier(t + myPos.x + myPos.z, 5);
}

void Particle::draw() {
	ofSetColor(myColor);
	ofDrawSphere(myPos, mySize);
	
}
void Particle::draw_as_spheres() {
	ofSetColor(myColor);
	ofDrawSphere(myPos, mySize);

}
void Particle::draw_as_cubes() {
	ofSetColor(myColor);
	ofDrawBox(myPos, mySize);

}
void Particle::draw_as_cones() {
	ofSetColor(myColor);
	ofDrawCone(myPos, mySize, mySize);

}

void Particle::setSize(float _size) {
	mySize = _size;
}

void Particle::setColor(ofColor _c) {
	myColor = _c;
}

void Particle::setAmp(float _amp) {
	myAmp = _amp;
}

void Particle::setNoiseBias(float _bias) {
	myNoiseBias = _bias;
}

void Particle::setNoiseGain(float _gain) {
	myNoiseGain = _gain;
}

void Particle::setFreq(float _freq) {
	myFreq = _freq;
}
