#pragma once

#include "ofMain.h"

#define WINDOW_X 800
#define WINDOW_Y 600

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector<float> xs;
        vector<float> ys;
        vector<float> d;
        vector<ofColor> c;
    
        bool needRedraw;
};
