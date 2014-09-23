#include "testApp.h"

//--------------------------------------------------------------
bool isMouseMoving() {
    static ofPoint pmouse;
    ofPoint mouse(ofGetMouseX(),ofGetMouseY());
    bool mouseIsMoving = (mouse!=pmouse);
    pmouse = mouse;
    return mouseIsMoving;
}

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(0,0,0);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update() {
    
    if (isMouseMoving()) {
        for(int i=0; i<flock.boids.size(); i++) {            
            flock.boids[i].avoid(ofPoint(mouseX,mouseY));
        }
    }
    
	flock.update();
}

//--------------------------------------------------------------
void testApp::draw() {
	flock.draw();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	flock.addBoid(x,y);
}






