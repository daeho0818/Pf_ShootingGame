#include "DXUT.h"
#include "cRifle.h"
#include "cMBullet.h"

cRifle::cRifle(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos), m_bullet(bullet)
{
	m_player = player;
	m_hp = 5;
	m_damage = 0.5;
	m_size = 10;
	mobName = "Rifle";
	mobType = "none";
}

cRifle::~cRifle()
{
	SAFE_DELETE(AS);
}

void cRifle::Update()
{
	if (AS != nullptr) AS->Update();
	m_pos.y += 5;
	Vec2 pos;
	D3DXVec2Normalize(&pos, &(m_player->m_pos - m_pos));


	if (fire && count <= 7)
	{
		AS = new cTimer(0.1, [&]()->void {fire = true; AS = nullptr; });
		m_bullet.push_back(new cMBullet(m_pos, pos, m_damage));
		count++;
		fire = false;
	}
}

void cRifle::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("mob_3"), m_pos, 0.2);
}

void cRifle::UIRender()
{
}