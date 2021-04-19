#pragma once

#include "ofMain.h"

class Symbol
{
public:
	Symbol(float _x, float _y, float _speed, float _first, float _opacity);
	float x;
	float y;
	float value;
	float speed;
	float opacity;
	float first;
	bool isFirst;
	int switchInterval;

	void setToRandomSymbol();
	void rain();
};

class Stream
{
public:
	Stream();
	void generateSymbols(float _x, float _y);
	void render();

	vector<Symbol> symbols;
	float totalSymbols;
	float speed;
};

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();
	vector<Stream> streams;
	void keyPressed(int key);
};
