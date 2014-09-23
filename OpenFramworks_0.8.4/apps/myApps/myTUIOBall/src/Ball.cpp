#include "ofMain.h"
#include "Ball.h"
#include <stdlib.h>
#include <math.h>

Ball::Ball(std::tr1::array<Ball*, BALL_NUMBER>* ballList, unsigned int idx, float x, float y)
{
	// tuio���� ���� x, y���� ȭ�鿡 ���� ��������̹Ƿ� 
	// ȭ�� ũ�⸸ŭ�� ���ؼ� �ش��ϴ� ��ġ�� �ȼ����� ����
	m_Position.x = x * WINDOW_WIDTH;
	m_Position.y = y * WINDOW_HEIGHT;

	// �� ó���� ������ �� ball�� ũ��
	m_Radius = 50.0f;

	// ������ ���� �������� ���� (��ġ �̺�Ʈ�� ����Ǹ� �̵�)
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;

	m_BallList = ballList;
	m_Idx = idx;

	// ��ġ �̺�Ʈ�� �����Ǵ� ���� ball�� ���� ��ȭ��Ű�� ���ؼ� ���Ǵ�
	// �� ����Ʈ ����
	m_colorList[0].r = 30;
	m_colorList[0].g = 153;
	m_colorList[0].b = 197;

	m_colorList[1].r = 196;
	m_colorList[1].g = 15;
	m_colorList[1].b = 132;

	m_colorList[2].r = 204;
	m_colorList[2].g = 232;
	m_colorList[2].b = 36;

	m_colorList[3].r = 78;
	m_colorList[3].g = 183;
	m_colorList[3].b = 153;

	m_colorList[4].r = 255;
	m_colorList[4].g = 102;
	m_colorList[4].b = 0;

	m_ColorIdx = 0;
	m_IsChanging = false;
}


Ball::~Ball(void)
{
}

void Ball::init()
{
	// ��ġ �̺�Ʈ�� ����� ������ ũ��� �� ��ȭ�� �ֱ����� flag ����
	m_IsChanging = true;
}

void Ball::setVelocity()
{	
	// ������ �������� �ӵ� �ο�
	m_Velocity.x = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
	m_Velocity.y = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
}

void Ball::update()
{
	// ���� ���� ��ġ �̺�Ʈ�� ������� ������ ball�� �Ӽ��� �����Ŵ
	if (m_IsChanging)
		changeBallProperties();

	// ���� �ӵ���ŭ ȭ�鿡�� �̵�
	m_Position += m_Velocity;
}

void Ball::draw()
{
	// ȭ�鿡 ball�� �׸�
	// �̶� ball�� ���� ���� ball�� m_ColorIdx�� �ش��ϴ� ������ ����
	// m_ColorIdx�� float�������� ����ĳ������ ���ؼ� �Ҽ��� ���� ������ ��� - �� ��ȭ �ӵ��� ����
	ofSetColor(m_colorList[static_cast<unsigned int>(m_ColorIdx) % COLOR_NUMBER]);
	ofCircle(m_Position.x, m_Position.y, m_Radius);
}

void Ball::changeBallProperties()
{
	// ball�� ũ�� ����
	m_Radius += 0.5;

	// ball�� �� ��ȭ
	// idx�� 0.1�� ������Ű�� ������ �ʹ� ���� �� ��ȭ�� ���� ����
	// 1�� ������Ű�� ball�� ���� �� ���� ������ó�� ����
	m_ColorIdx += 0.1f;
}

void Ball::stopIncreasing()
{
	m_IsChanging = false;
}

void Ball::checkBoundary()
{
	// ball�� ���� ��Ʈ�Ӹ��� ȭ�� ���� �� �Ѿ���� Ȯ��
	// ���� �Ѿ�� ��Ȳ�̸� x�� ������ � ������ �ݴ�� �ٲٰ�
	// ball�� ��ġ�� ȭ�� ���� ������ ����
	if (m_Position.x - m_Radius < 0)
	{
		m_Velocity.x *= -1;
		m_Position.x = m_Radius;
	}
	// ���� ���� �۾��� ������ ȭ�� �𼭸��� ���ؼ��� ����
	else if (m_Position.x + m_Radius > WINDOW_WIDTH)
	{
		m_Velocity.x *= -1;
		m_Position.x = WINDOW_WIDTH - m_Radius;
	}

	if (m_Position.y - m_Radius < 0)
	{
		m_Velocity.y *= -1;
		m_Position.y = m_Radius;
	}
	else if (m_Position.y + m_Radius > WINDOW_HEIGHT)
	{
		m_Velocity.y *= -1;
		m_Position.y = WINDOW_HEIGHT - m_Radius;
	}
}