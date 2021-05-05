#include "DXUT.h"
#include "cMHBullet.h"

cMHBullet::cMHBullet(Vec2 pos, cPlayer* player, float damage)
	:cBullet(pos, Vec2(0, 0), 10), m_player(player)
{
	m_Damage = damage;
	bulletType = "mob";
	time = new cTimer(1, [&]()->void {homing = false; time = nullptr; });
}

cMHBullet::~cMHBullet()
{
	SAFE_DELETE(time);
}

void cMHBullet::Update()
{
	if (time != nullptr) time->Update();
	if (homing)
		D3DXVec2Normalize(&m_Dir, &(m_player->m_pos - m_pos));
	m_pos += m_Dir * 600 * Delta;
	m_angle = atan2(m_Dir.y, m_Dir.x);
}

void cMHBullet::Render()
{
	if (homing)
		RENDER->CenterRender(IMAGE->FindImage("guided_bullets"), m_pos, 1, -m_angle);
	else
		RENDER->CenterRender(IMAGE->FindImage("effect_round_red"), m_pos, 1, -m_angle);
}