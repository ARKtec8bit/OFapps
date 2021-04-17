#pragma once

#include "ofMain.h"

class Walker
{
public:
	ofPoint pos;
	ofPoint prev;
	ofPoint step;
	ofColor wColor;
	Walker();
	void draw();
	void update(double _x);
};

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	vector<Walker> walks;
	int numWalks;

	void loadPiano();
	
	vector<ofSoundPlayer> voices;
	bool b_autoPlay;
	float tempo, currTime;
	int totalVoices;
	int bandsToGet;

	vector<float> output;
};
