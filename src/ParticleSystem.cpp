#include "ParticleSystem.h"

void ParticleSystem::setup() {
	setupParameters();

	int gridX = 100;
	int gridY = 100;

	for (int i=0; i<gridX; i++)
		for (int j = 0; j < gridY; j++) {
			vec3 pos = vec3(i - 0.5f * gridX, 0.0f, j - 0.5f * gridY);
			Particle par;
			par.setup(pos);
			myParticles.push_back(par);
		}
}

void ParticleSystem::update() {
	for (int i = 0; i < myParticles.size(); i++) {
		
		myParticles[i].setSize(size);
		myParticles[i].setColor(ofColor(r, g, b,a));
		myParticles[i].setAmp(amplitude);
		myParticles[i].setNoiseBias(noiseBias);
		myParticles[i].setNoiseGain(noiseGain);
		myParticles[i].setFreq(freq);
		myParticles[i].update();
	}
	if (spheres) {
		cubes = false;
		cones = false;
	}
	else if (cubes) {
		spheres = false;
		cones = false;
	}
	else if (cones) {
		spheres = false;
		cubes = false;
	}
}

void ParticleSystem::draw() {
	if(spheres) {
		for (int i = 0; i < myParticles.size(); i++) {
			myParticles[i].draw_as_spheres();
		}
	}
	else if (cubes) {
		for (int i = 0; i < myParticles.size(); i++) {
			myParticles[i].draw_as_cubes();
		}
	}
	else if (cones) {
		for (int i = 0; i < myParticles.size(); i++) {
			myParticles[i].draw_as_cones();
		}
	}
}

void ParticleSystem::setupParameters() {
	ps_parameters.setName("Particle System");
	
	//rendering parameters
	render_parameters.setName("Rendering Options");
	render_parameters.add(size.set("size", 0.1f, 0.1f, 1.0f));
	render_parameters.add(r.set("red", 62, 0, 255));
	render_parameters.add(g.set("green", 79, 0, 255));
	render_parameters.add(b.set("blue", 189, 0, 255));
	render_parameters.add(a.set("alpha", 255, 0, 255));
	render_parameters.add(spheres.set("spheres", true));
	render_parameters.add(cubes.set("cubes", false));
	render_parameters.add(cones.set("cones", false));
	ps_parameters.add(render_parameters);
	
	//motion parameters
	motion_parameters.setName("Motion Options");
	motion_parameters.add(amplitude.set("amplitude", 5.0f, 0.0f, 50.0f));

	//noise
	noise_parameters.setName("Noise");
	noise_parameters.add(noiseGain.set("Gain", 0.5f, 0.0f, 1.0f));
	noise_parameters.add(noiseBias.set("Bias", 0.5f, 0.0f, 1.0f));
	//sine motion
	sineW_parameters.setName("Sine Wave");
	sineW_parameters.add(freq.set("Frequency", 2.0f, 1.0f, 10.0f));
	
	motion_parameters.add(noise_parameters);
	motion_parameters.add(sineW_parameters);
	ps_parameters.add(motion_parameters);
}