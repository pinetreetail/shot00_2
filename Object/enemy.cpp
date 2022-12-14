#include "DxLib.h"
#include "game.h"
#include "enemy.h"
#include "SceneMain.h"

namespace
{
	
}

Enemy::Enemy() :
	m_pMein(nullptr),
	m_handle(-1),
	m_isExist(false),
	m_shotInterval(0),
	m_pos(),
	m_vec()
{
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth - 80.0f;
	m_pos.y = Game::kScreenHeight / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = true;
}

void Enemy::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	m_shotInterval++;
	if ((m_pMein) && (m_shotInterval >= 60))
	{
		m_pMein->createShot(m_pos);
		m_shotInterval = 0;
	}
}

void Enemy::draw()
{
	if (!m_isExist) return;
	//DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

int Enemy::getColWidth()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}
int Enemy::getColHeight()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}