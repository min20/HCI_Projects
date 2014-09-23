#include "testApp.h"
#define nullptr NULL

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(100, 100, 100);
	ofSetVerticalSync(true);
	
	//Connect to Port
	myTuio.connect(3333);
	
	//Assign Global TUIO Callback Functions
	ofAddListener(ofEvents().touchDown, this, &testApp::touchDown);
	ofAddListener(ofEvents().touchUp, this, &testApp::touchUp);
	ofAddListener(ofEvents().touchMoved, this, &testApp::touchMoved);

	ballIdx = 0;

	for (int i = 0; i < BALL_NUMBER; ++i)
	{
		ballList[i] = nullptr;
	}
}

//--------------------------------------------------------------
void testApp::update(){

	// ������Ʈ�� ������ ������ ball���� ȭ�� ������ �������� üũ�ϰ�
	// ���� �ӵ��� ���� ��ġ ��ȭ
	for (int i = 0; i < BALL_NUMBER; ++i)
	{
		if (ballList[i] != nullptr)
		{
			ballList[i]->checkBoundary();
			ballList[i]->update();
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//render TUIO Cursors and Objects
	myTuio.drawCursors();
	myTuio.drawObjects();

	// ������ ball�� ȭ�鿡 �׸�
	for (int i = 0; i < BALL_NUMBER; ++i)
	{
		if (ballList[i] != nullptr)
			ballList[i]->draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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


void testApp::touchDown(ofTouchEventArgs & touch){
	// touch.id�� ��ġ �̺�Ʈ�� �߻��� ������ 1�� ��� �����ؼ� �ش� �̺�Ʈ�� �Ҵ�
	int tempIdx = touch.id % BALL_NUMBER;

	if (ballList[tempIdx] != nullptr)
	{
		// ���� ��ⷯ ������ ����� ����� idx���� �̹� ball�� ���� ��� ����
		// ȭ���� ball ���� �����ϰ� ���� 
		delete ballList[tempIdx];
		ballList[tempIdx] == nullptr;
	}

	// idx�� �ش��ϴ� ball ����
	ballList[tempIdx] = new Ball(&ballList, touch.id, touch.x, touch.y);
	ballList[tempIdx]->init();
}

void testApp::touchUp(ofTouchEventArgs & touch){

	int tempIdx = touch.id % BALL_NUMBER;

	if (ballList[tempIdx] != nullptr)
	{
		// ��ġ�� ����Ǹ� ball�� ũ��� �� ��ȭ�� ���߰�
		ballList[tempIdx]->stopIncreasing();

		// ������ �ӵ��� �Ҵ�
		ballList[tempIdx]->setVelocity();
	}
}

void testApp::touchMoved(ofTouchEventArgs & touch){
	
}

