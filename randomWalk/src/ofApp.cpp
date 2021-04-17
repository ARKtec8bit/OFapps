#include "ofApp.h"

Walker::Walker()
{
    pos = ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    wColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Walker::update(double _x)
{
    float in = _x * 1000;

    float x = ofRandom(-in, in);
    float y = ofRandom(-in, in);

    prev = pos;
    ofPoint newPos = ofPoint(x, y);

    pos += newPos;

    if (pos.x > ofGetWidth())
    {
        pos.x = ofGetWidth();
    }
    if (pos.x < 0)
    {
        pos.x = 0;
    }
    if (pos.y > ofGetHeight())
    {
        pos.y = ofGetHeight();
    }
    if (pos.y < 0)
    {
        pos.y = 0;
    }
}
void Walker::draw()
{
    ofSetColor(wColor);
    ofSetLineWidth(5);

    ofDrawLine(pos, prev);
    //ofDrawCircle(pos, 5);
}

//--------------------------------------------------------------
void ofApp::setup()

{
    
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    numWalks = 512;
    bandsToGet = numWalks;
    for (int i = 0; i < numWalks; i++)
    {
        Walker w;
        walks.push_back(w);
    }
   
    loadPiano();
    tempo = 3000;
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (ofGetSystemTimeMillis() > currTime + tempo)
    {
        int num = ofRandom(totalVoices);
        voices[num].play();
        currTime = ofGetSystemTimeMillis();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(0, 50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    float *val = ofSoundGetSpectrum(bandsToGet);
    // for (int i= 0; i < bandsToGet; i ++){
    //     //cout << val[i]<< endl;
    //     output.push_back(val[i]);
    // }

    for (int j = 0; j < walks.size(); j++)
    {
        walks[j].update(val[j]);
        walks[j].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
       
        default:
            break;
    }
}

void ofApp::loadPiano()
{
    // load piano samples
    totalVoices = 8;
    voices.clear();
    for (int i = 0; i < totalVoices; i++)
    {
        ofSoundPlayer voice;
        string path = "/home/al/of/apps/myApps/randomWalk/bin/data/Piano-cut/Eno-Piano-0" + ofToString(i + 1) + ".wav";
        cout << "loading " << path << endl;
        voice.load(path);
        voice.setMultiPlay(true);
        voices.push_back(voice);
    }
}

