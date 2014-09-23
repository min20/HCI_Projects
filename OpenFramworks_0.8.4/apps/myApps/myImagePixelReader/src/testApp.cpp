#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	drawPixelGrid = false;
	pic.loadImage("test.jpg");
	fullSize = pic.width * pic.height;
	ofSetWindowShape(pic.width, pic.height);
	pixels = pic.getPixelsRef();
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetupScreen();
	pic.draw(0,0);
	if(drawPixelGrid) {
		for( int i = 0; i < 10; i++) {
			for( int j = 0; j < 10; j++) {
				ofSetColor( pixels.getColor(mouseX + i - 5, mouseY + j - 5 ), 200 );
				ofRect( mouseX + (i * 20 - 100), mouseY + (j * 20 - 100), 20, 20 );
			}
		}
	} else {
		ofSetColor(pixels.getColor(mouseX, mouseY), 200);
		ofCircle(mouseX, mouseY, 50);
	}
	ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	drawPixelGrid = !drawPixelGrid;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
