#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0,43,54);
    t = 0;
    _lines = 32;
    _step = 3;
    r = 6;
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
   
       
        for (float i = 0; i < _lines; i+=_step){
            ofSetColor(181, 137 , 0, 127);
            ofSetLineWidth(5);
            ofDrawLine(x1(t+i), y1(t+i), x2(t+i), y2(t+i));
            ofDrawCircle(x1(t + i), y1(t + i), r);
            ofDrawCircle(x2(t + i), y2(t + i), r);
        
        }
        for (float j = 0; j < _lines; j+=_step){
            ofSetColor(133, 153, 0, 127);
            ofSetLineWidth(5);
            ofDrawLine(x1(-t+j), y1(-t+j), x2(-t+j), y2(-t+j));
            ofDrawCircle(x1(-t + j), y1(-t + j), r);
            ofDrawCircle(x2(-t + j), y2(-t + j), r);
        }
        for (float k = 0; k < _lines; k+=_step){
            ofSetColor(220, 50, 47, 127);
            ofSetLineWidth(5);
            ofDrawLine(x1(-t+k), y1(t+k), x2(-t+k), y2(t+k));
            ofDrawCircle(x1(-t + k), y1(t + k), r);
            ofDrawCircle(x2(-t + k), y2(t + k), r);
        }
        for (float l = 0; l < _lines; l+=_step){
            ofSetColor(38, 139, 210, 127);
            ofSetLineWidth(5);
            ofDrawLine(x1(t+l), y1(-t+l), x2(t+l), y2(-t+l));
            ofDrawCircle(x1(t + l), y1(-t + l), r);
            ofDrawCircle(x2(t + l), y2(-t + l), r);
        }
    
    t+=0.5;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

float ofApp::x1(float t){
    return sin(-t / 10) * 100 + sin(t / 5) + 20;
}
float ofApp::y1(float t){
    return cos(-t / 10) * 100 + sin(t/5)* 50;
}
float ofApp::x2(float t){
    return sin(t / 10) * 200+ sin(t) * 2 + cos(t) * 10;
}
float ofApp::y2(float t){
    return -cos(t / 20) * 200 + cos(t / 12) * 20;

}