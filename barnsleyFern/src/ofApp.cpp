#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    x = 0;
    y = 0;
    ofSetBackgroundAuto(false);

    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    for (int red = 0; red < 500; red++){
        drawPoint();
        nextPoint();
    }
}

void ofApp::nextPoint(){
    float nextX;
    float nextY;

    float r = ofRandom(1);

    if (r < 0.01){
        nextX = 0;
        nextY = 0.16 * y;
    }
    else if (r < 0.86){
        nextX = 0.85 * x + 0.04 * y;
        nextY = -0.04 * x + 0.85 * y + 1.6;
    }
    else if (r < 0.93) {
    nextX =  0.20 * x + -0.26 * y;
    nextY =  0.23 * x +  0.22 * y + 1.6;
    } 
    else {
    nextX = -0.15 * x +  0.28 * y;
    nextY =  0.26 * x +  0.24 * y + 0.44;
    }

    x = nextX;
    y = nextY;

}

void ofApp::drawPoint(){
    
    ofSetLineWidth(1);
    float red, green, blue;
    double px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    double py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);
    if (py < ofGetHeight()/6){
    //red to yellow, green fading in
    red = 255;
    green = ofMap(py, 0, ofGetHeight()/6, 0, 255);
    blue = 0;
    } else if (py < ofGetHeight()/3) {
    //yellow to green, red fading out
    red = ofMap(py, ofGetHeight()/6, ofGetHeight()/3, 255, 0);
    green = 255;
    blue = 0;
    } else if (py < ofGetHeight()/2) {
    //green to cyan, blue fading in
    red = 0;
    green = 255;
    blue = ofMap(py, ofGetHeight()/3, ofGetHeight()/2, 0, 255);
    } else if (py < ofGetHeight()/1.5) {
    //cyan to blue, green fading out
    red = 0;
    green = ofMap(py, ofGetHeight()/2, ofGetHeight()/1.5, 255, 0);
    blue = 255;
    } else if (py < 4*ofGetHeight()/3) {
    //blue to purple, red fading in
    red = ofMap(py, ofGetHeight()/1.5, 4*ofGetHeight()/3, 0, 255);
    green = 0;
    blue = 255;
    } else {
    // purple to red, blue fading out
    red = 255;
    green = 0;
    blue = ofMap(py, ofGetHeight()/1.5, 4*ofGetHeight()/3, 0, 255);
    }
    ofNoFill();
    ofSetColor(red, green, blue, 50);
    ofDrawCircle(px, py, 1);
        }



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

