#include "ofApp.h"

Ball::Ball()
{
   

    pos = ofPoint(ofRandomWidth(), ofRandomHeight());
    vel = ofPoint(0, 0);
    color1.set(0, 255, 255);
    color2.set(255, 0, 255);
    color3.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update()
{   
    
    float transition = ofMap(pos.x, 0, ofGetWidth(), 0, 1);
    float angle = ofSignedNoise(pos.x / 200, pos.y / 200) * transition * TWO_PI * 180;
    float delta = ofSignedNoise(angle, transition);
    vel.x = cos(angle) * delta;
    vel.y = sin(angle) * delta;
    vel *= (delta);
    pos += (vel);
    
}
void Ball::draw()
{
    ofSetColor(color3,170);
    ofDrawCircle(pos, 1);
}
void Ball::edge()
{
   
    if (pos.x > ofGetWidth() || pos.x < 0 || pos.y > ofGetHeight() || pos.y < 0)
    {
        pos.x = ofRandomWidth();
        pos.y = ofRandomHeight();
        
    }
}

void Ball::run()
{
    edge();
    draw();
    update();
}
//--------------------------------------------------------------
void ofApp::setup()
{
    number = 10000;
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);
    for (int i = 0; i < number; i++)
    {
        Ball b;
        balls.push_back(b);
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
    ofSetColor(0, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    for (int i = 0; i < balls.size(); i++)
    {
        balls[i].run();
       
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
