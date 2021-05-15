
// BoxCloud code by Dan Buzzo
// modified By ARKtec8Bit
// music N109 BarkersEggs Recordings


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    //ofSetFrameRate(15);
    bandsToGet = 16;
    int maxBoxes = 480;
    spaceRange = 300;
    ofEnableDepthTest();
    ofSetBackgroundColor(0);
    light1.setPosition(0, 0, 0);
    light1.setAmbientColor(ofColor::blue);
    light1.enable();
    light2.setPosition(-500, 500, 500);
    light2.setSpecularColor(ofColor::greenYellow);
    light2.setDirectional();
    light2.enable();

    for (size_t i = 0; i < maxBoxes; i++)
    {
        ofBoxPrimitive newBox;
        newBox.set(ofRandom(50, 100),
                   ofRandom(50, 100),
                   ofRandom(50, 100));
        newBox.setPosition(ofRandom(-spaceRange, spaceRange),
                           ofRandom(-spaceRange, spaceRange),
                           ofRandom(-spaceRange, spaceRange));
        for (int side = 0; side < 6; side++)
        {
            newBox.setSideColor(side, ofColor(ofRandom(255), ofRandom(200, 250)));
        }
        boxes.push_back(newBox);
    }

    sounds.load("moredogchalk_cleaned.ogg");
    sounds.setMultiPlay(true);
    sounds.play();
}

//--------------------------------------------------------------
void ofApp::update()
{
    float *val = ofSoundGetSpectrum(bandsToGet);

    
    for (int j = 0; j < bandsToGet; j++)
    {
        for (int i = 0; i < boxes.size(); i++)
        {
            // make groups of boxes based on bands
            if (fmod(i, j) == 0 && ofRandom(100) < 10 || val[j] > .5)
            {
                float x = val[j] * 100.0;
                cout<< x<< endl;
                boxes[i].setPosition(ofRandom(-spaceRange * x, spaceRange * x) / 30,
                                     ofRandom(-spaceRange * x, spaceRange * x) / 30,
                                     ofRandom(-spaceRange * x, spaceRange * x) / 30);
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    float time = ofGetSystemTimeMillis() / 100.0;
    cam.begin();

    ofPushMatrix();
    ofRotateXDeg(time);
    ofRotateZDeg(-time);
    ofRotateYDeg(time / 2);
    for (size_t i = 0; i < boxes.size(); i++)
    {

        boxes[i].draw();
    }
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case 'f':
    case 'F':
        ofToggleFullscreen();
        break;

    case OF_KEY_UP:
        spaceRange += 10;
        break;

    case OF_KEY_DOWN:
        spaceRange -= 10;
        break;

    default:
        break;
    }
}
