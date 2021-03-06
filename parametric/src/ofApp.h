#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		float x1(float t);
		float x2(float t);
		float y1(float t);
		float y2(float t);
		float t;
		int _lines;
		float _step;
		int r;
};
