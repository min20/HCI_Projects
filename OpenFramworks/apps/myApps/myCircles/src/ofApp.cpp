#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor(200, 200, 200);
    int WINDOW_X = ofGetWidth();
    int WINDOW_Y = ofGetHeight();
    
    ofNoFill();
    for (int idx = 0; idx < 50; idx++) {
        ofCircle(WINDOW_X / 2 - (WINDOW_X / 2 - mousePoint.x) / 50.0 * idx,
                 WINDOW_Y / 2 - (WINDOW_Y / 2 - mousePoint.y) / 50.0 * idx,
                 idx * 2);
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
    mousePoint.x = x;
    mousePoint.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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