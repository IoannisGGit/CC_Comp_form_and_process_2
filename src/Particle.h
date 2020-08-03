#pragma once

#include "ofMain.h"

using namespace glm;

class Particle {
public:
	void setup(vec3 initPos);
	void update();
	void draw();

	void draw_as_spheres();
	void draw_as_cubes();
	void draw_as_cones();

	void setSize(float _size);
	void setColor(ofColor _c);

	void setAmp(float _amp);
	void setNoiseBias(float _bias);
	void setNoiseGain(float _gain);
	void setFreq(float _freq);



private:
	vec3 myPos;
	vec3 myVel;
	float mySize;
	ofColor myColor;
	float myAmp;
	float myNoiseBias;
	float myNoiseGain;
	float myFreq;

	
};
