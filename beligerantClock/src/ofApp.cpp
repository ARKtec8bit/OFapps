#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(1);
    font.load("fethnocentric rg.ttf", 65);
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
  
}
//--------------------------------------------------------------
void ofApp::draw(){
   
    ofPushMatrix(); 
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofSetColor(0,255,0,255);
    ofRotateDeg( (ofGetSeconds() * 6)-90 );
    
    for (int x = 1; x < 7; x++){
        // font.drawString( "fuck", 50, 0 );
        font.drawString(ofToString(ofGetSeconds()), 50, 0 );
        ofRotateDeg(-x);
        ofSetColor(0,125-(x*10),0,150-(x*10));
    }
    ofPopMatrix();

    ofSetColor(255,0,0,255);   
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateDeg( (ofGetMinutes() * 6) - 90 );
    for (int x = 1; x < 7; x ++){
        ofRotateDeg(-x);
        // if (ofGetMinutes()%2  == 0){
        //     font.drawString("this", 150,0 );
        // } else {
        //     font.drawString("that", 150,0 );
        // }
        font.drawString(ofToString(ofGetMinutes()), 150,0 );
        ofSetColor(125-(x*10),0,0,150-(x*10));
        }
    ofPopMatrix();
    
    ofSetColor(0,0,255,255);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateDeg( (ofGetHours() * 30 ) - 90 );
     for (int x = 1; x < 7; x ++){
        ofRotateDeg(-x);
        //font.drawString("shit", 250,0 );
        font.drawString(ofToString(ofGetHours()), 250,0 );
        ofSetColor(0,0,125-(x*10),150-(x*10));
    }
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
