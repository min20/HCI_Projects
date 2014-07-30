#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(250, 250, 250);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    for (int idx = 0; idx < 10; idx++) {
        planet p = getNewPlanet();
        planets.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float amplitude = 200.0;
    
    for (int idx = 0; idx < planets.size(); idx++) {
        float wavelength = 20.0 * planets.at(idx).orbitSize;
        planets.at(idx).pos.x = amplitude * planets.at(idx).orbitSize * cos(ofGetFrameNum() / wavelength) + mouseX;
        planets.at(idx).pos.y = amplitude * planets.at(idx).orbitSize * sin(ofGetFrameNum() / wavelength) + mouseY;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    for (int idx = 0; idx < planets.size(); idx++) {
        planet p = planets.at(idx);
        
        ofSetColor(p.color);
        ofCircle(p.pos.x, p.pos.y, p.radius);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    planet p = getNewPlanet();
    planets.push_back(p);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


// My Function
planet ofApp::getNewPlanet() {
    planet p;
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    p.radius = ofRandom(40) + 5.0f;
    p.pos.x = ofRandom(w);
    p.pos.y = ofRandom(h);
    p.orbitSize = ofRandom(2.0) + 0.5;
    p.color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    return p;
}