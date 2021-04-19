#pragma once

#include "ofMain.h"

class Ball{
	public:
	Ball();
	float c;
	ofPoint pos;
	ofPoint vel;
	ofPoint gravity;
	ofColor color1;
	ofColor color2;
	ofColor color3;
	void update();
	void edge();
	void draw();
	void run();
	

};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		vector<Ball> balls;
		int number;
		
};
