#pragma once
#include "config.h"
#include "tr1/array"

class Ball
{
public:
	// ball���� �����ϱ� ���� list�� �ش� ball�� idx�� ���ڿ� ���� ������ �浹üũ�� �ʿ��� ��� Ȱ���ϱ� ����
	// x, y���� �����Ǵ� ball�� ȭ�鿡 ��ġ�� �������� �����ǰ� �ϱ� ���ؼ� �Է�
	Ball(std::tr1::array<Ball*, BALL_NUMBER>* ballList, unsigned int idx, float x, float y);
	~Ball(void);

	// ball�� ũ��� �� ��ȭ�� ���� flag ����
	void init();

	// ball�� �����̴� ������ �ӵ� �ο�
	void setVelocity();

	// ball�� �����Ӱ� ũ��, �� ��ȭ�� ����
	void update();

	// ȭ�鿡 ball�� �׸�
	void draw();

	// ball�� �����̴ٰ� ȭ�� ������ �������� Ȯ���ؼ�
	// ������ �ʵ��� �ӵ� ��ȭ
	void checkBoundary();

	// ball�� ũ�⸦ ������Ű�� ���� ��ȭ ��Ŵ
	void changeBallProperties();

	// ball�� ũ�� ������ ����
	void stopIncreasing();

	// get / set functions
	void	setRadius(float radius)		{ m_Radius = radius; }
	float	getRadius()					{ return m_Radius; }
	ofVec3f getPosition()				{ return m_Position; }
	ofVec3f getVelocity()				{ return m_Velocity; }
	void setVelocity(ofVec3f change)	{ m_Velocity = change; }

private:
	unsigned int m_Idx;
	float m_ColorIdx;

	bool m_IsChanging;

	ofVec3f m_Position;
	float m_Radius;

	ofVec3f m_Velocity;

	std::tr1::array<Ball*, BALL_NUMBER>* m_BallList;
	std::tr1::array<ofColor, COLOR_NUMBER> m_colorList;
};

