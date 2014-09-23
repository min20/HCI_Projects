#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    needRedraw = false;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (!needRedraw) {
        return;
    }
    
    ofBackground(250, 250, 250);
    float w = ofGetWidth();
    float h = ofGetHeight();
    int step = 1;
    
    for (int x = 0; x < w && xs.size() > 0; x += step) {
        for (int y = 0; y < h && ys.size() > 0; y += step) {
            int idx = 0;
            float dd;
            dd = ofDist(xs[0], ys[0], x, y);
            
            for (int i = 1; i < d.size(); i++) {
                float d0 = ofDist(xs[i], ys[i], x, y);
                if (dd > d0) {
                    dd = d0;
                    idx = i;
                }
            }
            ofSetColor(c[idx]);
            ofRect(x, y, step, step);
        }
    }
    
    ofSetColor(255);
    for (int i = 0; i < xs.size(); i++) {
        ofEllipse(xs[i], ys[i], 5, 5);
    }
    
    needRedraw = false;
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
    xs.push_back(x);
    ys.push_back(y);
    d.push_back(0);
    ofColor c1(ofRandom(255), ofRandom(255), ofRandom(255));
    c.push_back(c1);
    
    needRedraw = true;
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