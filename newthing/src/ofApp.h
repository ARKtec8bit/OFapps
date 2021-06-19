#pragma once

#include "ofMain.h"

class Particle{
	public:
		
		Particle(ofPoint _loc, int _hue);
		ofPoint initial;
		void show();
		void update();
		ofPoint loc;
		ofPoint vel;
		ofPoint force;
		float hue;
		float size;
		ofColor colour;
		float life;
		bool isDead;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void generatePoints();
		void generateParticles();

		vector<ofPoint> points;
		int numPoints;

		vector<Particle> particles;
		int numParticles;
		
		ofColor particleColour;


		
};
