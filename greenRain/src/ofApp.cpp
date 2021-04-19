#include "ofApp.h"

float fadeInterval = 1.6;
float symbolSize = 14;

Symbol::Symbol(float _x, float _y, float _speed, float _first, float _opacity)
{
    x = _x;
    y = _y;
    value;
    speed = _speed;
    opacity = _opacity;
    first = _first;
    switchInterval = round(ofRandom(2, 25));
}
void Symbol::setToRandomSymbol()
{
    int charType = round(ofRandom(0, 5));
    if (ofGetFrameNum() % switchInterval == 0)
    {
        if (charType > 1)
        {
            value = 0x30A0 + floor(ofRandom(0, 97));
        }
        else
        {
            value = floor(ofRandom(0, 97));
        }
    }
}
void Symbol::rain()
{
    y = (y >= ofGetHeight()) ? 0 : y += speed;

}

Stream::Stream()
{
    totalSymbols = round(ofRandom(5, 35));
    speed = ofRandom(1, 10);
}
void Stream::generateSymbols(float _x, float _y)
{
    float x = _x;
    float y = _y;
    float opacity = 255;
    bool first = ofRandom(0,4) == true;
    for (int i = 0; i <= totalSymbols; i++)
    {
        Symbol symbol(x, y, speed, first, opacity);
        symbol.setToRandomSymbol();
        symbols.push_back(symbol);
        opacity -= (255 / totalSymbols) / fadeInterval;
        y -= symbolSize;
        first = false;
    }
}
void Stream::render()
{
    for (int s = 0; s < symbols.size(); s++)
    {
        if (symbols[s].first)
        {

            ofSetColor(140, 255, 170, symbols[s].opacity);
        }
        else
        {

            ofSetColor(0, 255, 70, symbols[s].opacity);
        }

        ofDrawBitmapString(u_char(symbols[s].value), symbols[s].x, symbols[s].y);
        //ofDrawCircle(symbols[s].x, symbols[s].y, 9);

        symbols[s].rain();
        symbols[s];
        symbols[s].setToRandomSymbol();
    }
}

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);
    int x = 0;
    for (int i = 0; i <= ofGetWidth() / symbolSize; i++)
    {
        Stream stream;
        stream.generateSymbols(x, ofRandomHeight());
        streams.push_back(stream);
        x += symbolSize;
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()

{
    ofEnableAlphaBlending();
    // ofClear(0, 0, 0);
    ofSetColor(0, 50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for (int x = 0; x < streams.size(); x++)
    {
        streams[x].render();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
