#include "DXUT.h"
#include "cSideMove.h"
#include "cMBullet.h"
#include "cMHBullet.h"

cSideMove::cSideMove(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos), m_bullet(bullet)
{
	random = rand() % 2;
	m_player = player;
	m_hp = 5;
	m_damage = 1;
	m_size = 10;
	mobName = "SideMove";
	mobType = "none";
}

cSideMove::~cSideMove()
{
	SAFE_DELETE(AS);
}

void cSideMove::Update()
{
	if (AS != nullptr) AS->Update();

	MoveToSide();
	m_pos.y += 3;

	if (fire)
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_player->m_pos - m_pos));
		AS = new cTimer(0.5, [&]()->void {fire = true; AS = nullptr; });
		m_bullet.push_back(new cMBullet(m_pos, Vec2(0, 1), m_damage));
		//m_bullet.push_back(new cMHBullet(m_pos, m_player, m_damage));
		fire = false;
	}
}

void cSideMove::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("mob_1"), m_pos, 0.2);
}
void cSideMove::UIRender()
{
}
void cSideMove::MoveToSide()
{
	if (random == 0)
		m_pos.x += 3;
	else
		m_pos.x -= 3;
}