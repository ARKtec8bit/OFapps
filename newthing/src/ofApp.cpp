#include "ofApp.h"

Particle::Particle(ofPoint _loc, int _hue)
{
    loc = _loc;
    initial = _loc;
    hue = _hue;
    size = ofRandom(3,10);
    vel.set(ofRandom(-4, 4), ofRandom(-4, 4));
    force.set(ofRandom(-0.05,0.05), ofRandom(0.01,0.09));
    colour.setHsb(hue, 255, 255, 150);
    life = 100;
    isDead = false;
}

void Particle::update()
{
    loc += vel;
    vel += force;
    life --;

     if (size > 0){
            size -=0.07;
        }
        float brightness = colour.getBrightness();
        float myHue = colour.getHue();
        
    
        if (brightness >20){
            colour.setBrightness( brightness -=0.05 );
            float d = ofMap(ofDist(initial.x,initial.y, loc.x,loc.y), 0, 20, .01, .5);
            colour.setHue( myHue -=d);
    
        }
    if(life < 1 && size < 1){
        isDead = true;
    }
}

void Particle::show()
{

    ofSetColor(colour);
    ofDrawCircle(loc, size);
}

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(0);

    numPoints = 30;
    numParticles = 100;
    generatePoints();
}

void ofApp::generateParticles()
{

    for (int i = 0; i < numPoints; i++)
    {
        int hue = ofRandom(255);
        for (int j = 0; j < numParticles; j++)
        {
            Particle P(points[i], hue);
            particles.push_back(P);
        }
    }
}

void ofApp::generatePoints()
{
    points.clear();
    //particles.clear();
    for (int i = 0; i < numPoints; i++)
    {
        points.push_back(ofPoint(ofRandomWidth(), ofRandomHeight()));
    }
    generateParticles();
}

//--------------------------------------------------------------
void ofApp::update()
{   for (int i = 0; i < particles.size(); i++)
    {
        if(particles[i].isDead){
          particles.erase(particles.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].update();
        particles[i].show();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_RETURN)
    {
        generatePoints();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------