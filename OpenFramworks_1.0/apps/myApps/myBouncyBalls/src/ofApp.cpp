#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	numBalls = 8;
	spring = 0.3;
	gravity = 0.5;
	friction = -0.3;
    
    barX = ofGetWidth() / 2 - barWidth / 2;
    barY = ofGetHeight() - barHeight;
    
	width = ofGetWidth();
	height= ofGetHeight();
	
	for(int i=0;i<numBalls;i++) {
        createBall();
	}
	
	ofSetFrameRate(60);
	ofBackground(100,100,100);
	ofSetVerticalSync(true);
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i=0; i < balls.size();i++) {
		balls[i]->move();
	}
    
	checkCollision();
    checkBallOut();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(100,100,100);
    
    ofSetColor(0,255,255,100);
	for(int i=0;i < balls.size();i++) {
		balls[i]->display();
	}
    
    ofSetColor(233, 233, 233, 233);
    ofRect(barX, barY, barWidth, barHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 356) {
        barX -= 30;
    } else if (key == 358 ) {
        barX += 30;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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


// My Functions
void ofApp::createBall() {
    Ball *ball = new Ball();
    ball->setup(ofRandom(ofGetWidth()), 0 - ofRandom(ofGetHeight()), ofRandom(30,70), spring, gravity, friction);
    balls.push_back(ball);
}

void ofApp::checkCollision(void) {
	for(int i=0;i< balls.size();i++) {
		for(int j=i+1;j< balls.size();j++) {
			float dx = balls[j]->x - balls[i]->x;
			float dy = balls[j]->y - balls[i]->y;
			float distance = ofDist(balls[i]->x,balls[i]->y,balls[j]->x,balls[j]->y);
			float minDist = balls[j]->diameter/2 + balls[i]->diameter/2;
            
            // Check with other balls
			if (distance < minDist) {
				float angle = atan2(dy,dx);
				float targetX = balls[i]->x + cos(angle) * minDist;
				float targetY = balls[i]->y + sin(angle) * minDist;
				float ax = (targetX - balls[j]->x) * spring;
				float ay = (targetY - balls[j]->y) * spring;
				balls[i]->vx -= ax;
				balls[i]->vy -= ay;
				balls[j]->vx += ax;
				balls[j]->vy += ay;
			}
            
            // Check with bar
            if (barX < balls[i]->x + balls[i]->diameter/2
                    && balls[i]->x - balls[i]->diameter/2 < barX + barWidth) {
                if (balls[i]->y + balls[i]->diameter / 2 > barY) {
                    balls[i]->y = barY - balls[i]->diameter/2;
                    balls[i]->vy *= friction;
                    
                    if(barX + barWidth/2 > balls[i]->x) {
                        balls[i]->vx -= 1;
                    } else {
                        balls[i]->vx += 1;
                    }
                }
            }
            
		}
	}
}

void ofApp::checkBallOut() {
    for (int i = 0; i < balls.size(); i++) {
        Ball * ball = balls[i];
        if (ball->y - ball->diameter/2 > ofGetHeight()) {
            balls.erase(balls.begin() + i);
            delete(ball);
            createBall();
        }
    }
}


