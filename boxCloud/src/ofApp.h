#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	vector<ofBoxPrimitive> boxes;
	ofEasyCam cam;
	ofLight light1;
	ofLight light2;
	int spaceRange;
	int bandsToGet;
	ofSoundPlayer sounds;
};
