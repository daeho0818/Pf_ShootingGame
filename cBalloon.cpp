#include "DXUT.h"
#include "cBalloon.h"
#include "cMHBullet.h"
#include "cMBullet.h"

cBalloon::cBalloon(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	: cMob(pos), m_bullet(bullet)
{
	m_player = player;
	m_hp = 3;
	m_damage = 1;
	m_size = 20;
	mobName = "Ballon";
	mobType = "none";
}

cBalloon::~cBalloon()
{
	SAFE_DELETE(AS);
}

void cBalloon::Update()
{
	if (AS != nullptr) AS->Update();
	m_pos.y += 3;

	if (fire)
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_player->m_pos - m_pos));
		AS = new cTimer(1.5, [&]()->void {fire = true; AS = nullptr; });
		m_bullet.push_back(new cMBullet(m_pos, pos, m_damage));
		fire = false;
	}
}

void cBalloon::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("mob_2"), m_pos, 0.2);
}
void cBalloon::UIRender()
{
}