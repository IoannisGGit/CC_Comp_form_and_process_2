#pragma once

#include "ofMain.h"
#include "Particle.h"

using namespace glm;

class ParticleSystem {
public:
	void setup();
	void update();
	void draw();

	ofParameterGroup ps_parameters;

	ofParameterGroup render_parameters;
	ofParameter<float> size;
	ofParameter <int> r, g, b, a;
	ofParameter <bool> spheres, cubes, cones;

	ofParameterGroup motion_parameters;
	ofParameter<float> amplitude;
	ofParameterGroup noise_parameters;
	ofParameter<float> noiseBias;
	ofParameter<float> noiseGain;
	ofParameterGroup sineW_parameters;
	ofParameter<float> freq;
	
	

private:
	void setupParameters();
	vector<Particle> myParticles;

};