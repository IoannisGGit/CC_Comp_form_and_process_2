#pragma once

#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
float remapNoise(float x, float min, float max) {
	return ofMap(ofNoise(x), 0.2f, 0.8f, min, max);
}

//--------------------------------------------------------------
float remapNoise(float x) {
	return remapNoise(x, 0.0f, 1.0f);
}

//--------------------------------------------------------------
float noiseWithOctaves(float x, int numOctaves) {
	float result = 0.0f;

	float freq = 1.0f;
	float amp = 1.0f;
	for (int i = 0; i < numOctaves; i++) {
		result += amp * ofNoise(freq * x);
		freq *= 2.0f;
		amp *= 0.5f;
	}

	return result;
}

//--------------------------------------------------------------
float noiseWithOctaves(vec2 v, float baseFrequency, int numOctaves) {
	float result = 0.0f;

	float freq = baseFrequency;
	float amp = 1.0f;
	for (int i = 0; i < numOctaves; i++) {
		//result += amp * ofMap(ofNoise(freq * v), 0.2f, 0.8f, -0.2f, 0.2f);
		result += amp * ofNoise(freq * v);
		freq *= 2.0f;
		amp *= 0.5f;
	}

	return result + 0.5f;
}

//--------------------------------------------------------------
float fourier(float x, int numHarmonics) {
	float result = 0.0f;
	for (int i = 0; i < numHarmonics; i++) {
		//int n = 2 * i + 1;
		int n = i + 1;
		result += (1.0f / n) * sinf(x * n);
	}

	return result;
}

//--------------------------------------------------------------
float bias(float x, float b)
{
	return x / (((1.0f / b - 2.0f)*(1.0f - x)) + 1.0f);
}

//--------------------------------------------------------------
float gain(float x, float g)
{
	if (x < 0.5f)
		return bias(x * 2.0f, g) / 2.0f;
	else
		return bias(x * 2.0f - 1.0f, 1.0f - g) / 2.0f + 0.5f;
}
