#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fontMessage.loadFont("Replica Regular.otf",13);
	ofBackground(50,50,50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255, 10);
	//ofCircle(mousePoint, 50);
	for(int i = 0; i < circlePosition.size(); i++) {
		ofCircle(circlePosition[i], radius[i]);
	}
	ofSetColor(255, 255, 255, 100);
	fontMessage.drawString(eventMessage, 20, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	//mousePoint.x = x;
	//mousePoint.y = y;
    int targetIdx = -1;
    long currentDistance = -1;
    long long leastDistance = LONG_LONG_MAX;
    switch(button) {
        case 0:
            sprintf(eventMessage,"left mouse pressed at (%d, %d)",x,y);
            circlePosition.push_back(ofPoint(x,y));
            radius.push_back(30 + (x + y) % 40);
            break;
        case 1:
            sprintf(eventMessage,"middle mouse pressed at (%d, %d)",x,y);
            break;
        case 2:
            sprintf(eventMessage,"right mouse pressed at (%d, %d)",x,y);
            if (circlePosition.empty()) {
                sprintf(eventMessage,"list is empty!");
                break;
            }
            
            for (int idx = circlePosition.size() - 1; idx >= 0; --idx) {
                currentDistance = (circlePosition[idx].x - x) * (circlePosition[idx].x - x)
                        + (circlePosition[idx].y - y) * (circlePosition[idx].y - y);
                
                if (currentDistance > radius[idx] * radius[idx]) {
                    continue;
                }
                
                if (currentDistance < leastDistance) {
                    leastDistance = currentDistance;
                    targetIdx = idx;
                }
                cout << idx << " " << targetIdx << " " << currentDistance << " " << leastDistance << endl;
            }
            
            
            if (targetIdx == -1 || currentDistance == -1) {
                break;
            }
            
            circlePosition.erase(circlePosition.begin() + targetIdx);
            radius.erase(radius.begin() + targetIdx);
            break;
        default:
            sprintf(eventMessage,"mouse pressed at (%d, %d)",x,y);
            break;
    }
    
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
