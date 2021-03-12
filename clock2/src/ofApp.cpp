#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    font.load("neon_pixel-7.ttf", 30);

}

//--------------------------------------------------------------
void ofApp::update(){
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateRad(-HALF_PI);

    int secs = ofGetSeconds();
    int mins = ofGetMinutes();
    int hours = ofGetHours() % 12;
    int day = ofGetDay();
    int month = ofGetMonth();
    int year = ofGetYear();
    float secondAngle = ofMap(secs, 0, 60, 0, TWO_PI);
    float minuteAngle = ofMap(mins, 0, 60, 0, TWO_PI);
    float hourAngle = ofMap(hours , 0, 12, 0, TWO_PI);
    float dayAngle = ofMap(day , 0 , 31, 0, TWO_PI);
    float monthAngle = ofMap(month, 0, 12, 0, TWO_PI);
    float yearAngle = ofMap(year % 4, 0, 4, 0, TWO_PI);
  

    ofPushMatrix();
    ofSetColor(0,255,0);
    ofRotateRad(secondAngle);
    for(int x = 0; x < 12; x ++){
        font.drawString(ofToString(secs), 150,0);
        //font.drawString("Fuck", 125,0);
        ofRotateDeg(-x);
        ofSetColor(0,127,0, 127 - (x * 10));
    }
    ofPopMatrix();

    ofPushMatrix();
    ofSetColor(255,0,0);
    ofRotateRad(minuteAngle);
    for(int x = 0; x < 12; x ++){
       font.drawString(ofToString(mins), 225,0);
        // if(mins % 2 == 0){
        //     font.drawString("This", 200,0);
        // }else{
        //     font.drawString("That", 200,0);
        // }
        ofRotateDeg(-x);
        ofSetColor(127,0,0, 127 - (x * 10));
    }
    ofPopMatrix();

    ofPushMatrix();
    ofSetColor(0,0,255);
    ofRotateRad(hourAngle);
    for(int x = 0; x < 12; x ++){
        font.drawString(ofToString(hours), 300,0);
       // font.drawString("Shit", 275,0);
        ofRotateDeg(-x);
        ofSetColor(0,0,127, 127 - (x * 10));
    }
    ofPopMatrix();
    

    ofPushMatrix();
    ofSetColor(0,255,255);
    ofRotateRad(dayAngle);
    font.drawString(ofToString(day), 100,0);    
    ofPopMatrix();

    ofPushMatrix();
    ofSetColor(255,0,255);
    ofRotateRad(monthAngle);
    font.drawString(ofToString(month), 75,0);    
    ofPopMatrix();

    ofPushMatrix();
    ofSetColor(255,255, 0);
    ofRotateRad(yearAngle);
    font.drawString(ofToString(year), 5,0);    
    ofPopMatrix();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
     switch (key) {
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
