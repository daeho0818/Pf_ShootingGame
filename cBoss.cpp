#include "DXUT.h"
#include "cBoss.h"
#include "cMHBullet.h"
#include "cMBullet.h"

cBoss::cBoss(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet, int mobNumber)
	:cMob(pos), m_bullet(bullet), mobNumber(mobNumber)
{
	m_player = player;
	m_hp = 50;
	m_damage = 1;
	m_size = 20;
	mobName = "Boss";
	mobType = "Boss";
	curPos = m_pos;
	if (mobNumber == 0)
	{
		UIPos = Vec2(600, 30);
	}
	else if (mobNumber == 1)
	{
		UIPos = Vec2(600, 30);
	}
	else if (mobNumber == 2)
	{
		UIPos = Vec2(600, 60 + IMAGE->FindImage("Hp")->info.Height / 2);
	}
}

cBoss::~cBoss()
{
	SAFE_DELETE(Pattern1T);
	SAFE_DELETE(Pattern2T);
	SAFE_DELETE(Pattern3T);
	SAFE_DELETE(Pattern4T);
}

void cBoss::Update()
{
	if (Pattern1T != nullptr) Pattern1T->Update();
	if (Pattern2T != nullptr) Pattern2T->Update();
	if (Pattern3T != nullptr) Pattern3T->Update();
	if (Pattern4T != nullptr) Pattern4T->Update();

	if (m_pos.y <= 200)
		m_pos.y += 3;
	else
	{
		Pattern1();
		Pattern2();
		Pattern3();
	}
}

void cBoss::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("boss"), m_pos, 2);
}

void cBoss::UIRender()
{
	RECT hprc =
	{
		0,
		0,
		(float)IMAGE->FindImage("Hp")->info.Width / 10 * m_hp,
		IMAGE->FindImage("Hp")->info.Height / 2
	};
	UI->CropRender(IMAGE->FindImage("Hp"), UIPos, hprc);
}

void cBoss::Pattern1()
{
	if (pattern1)
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_player->m_pos - m_pos));
		Pattern1T = new cTimer(2.5, [&]()->void {
			pattern1 = true;
			Pattern1T = nullptr;
			});

		m_bullet.push_back(new cMBullet(Vec2(m_pos.x -= 50, m_pos.y), pos, m_damage));
		m_bullet.push_back(new cMBullet(Vec2(m_pos.x -= 100, m_pos.y), pos, m_damage));
		m_bullet.push_back(new cMBullet(Vec2(m_pos.x += 50, m_pos.y), pos, m_damage));
		m_bullet.push_back(new cMBullet(Vec2(m_pos.x += 100, m_pos.y), pos, m_damage));

		pattern1 = false;
	}
}

void cBoss::Pattern2()
{
	if (pattern2)
	{
		float  angle = 0;
		float  rad = D3DX_PI * 2 / 25;
		Pattern2T = new cTimer(10, [&]()->void {
			pattern2 = true;
			Pattern2T = nullptr;
			});
		for (float i = 0; i < 25; i++, angle += rad)
		{
			Vec2 Direction = Vec2(m_pos.x + (cosf(angle) * 5), m_pos.y + (sinf(angle) * 5));
			Direction = Direction - m_pos;
			D3DXVec2Normalize(&Direction, &Direction);
			m_bullet.push_back(new cMBullet(m_pos, Direction, m_damage, 10, 400));

			if (Pattern4T == nullptr && SCENE->stage == 0)
			{
				Pattern4T = new cTimer(2, [&]()->void {
					for (auto iter : m_bullet)
					{
						Vec2 Dir = m_pos - iter->m_pos;
						D3DXVec2Normalize(&Dir, &Dir);
						iter->m_Dir = Dir;
					}
					Pattern4T = nullptr;
					});
			}
		}
		pattern2 = false;
	}
}

void cBoss::Pattern3()
{
	if (mobNumber != 0)
	{
		if (pattern3)
		{
			if (chkLR == 'L' && bMove)
				D3DXVec2Lerp(&m_pos, &m_pos, &Vec2(100, m_pos.y), 0.04);
			else if (chkLR == 'R' && bMove)
				D3DXVec2Lerp(&m_pos, &m_pos, &Vec2(1400, m_pos.y), 0.04);
			if (bMove)
			{
				m_bullet.push_back(new cMBullet(Vec2(m_pos.x + 10, m_pos.y),
					Vec2(0, 1), m_damage, 10, 500));
				m_bullet.push_back(new cMBullet(Vec2(m_pos.x - 10, m_pos.y),
					Vec2(0, 1), m_damage, 10, 500));
				if (m_pos.x > 1399)
				{
					chkLR = 'L';
					count++;
				}
				else if (m_pos.x < 101)
				{
					chkLR = 'R';
					count++;
				}
			}
			if (count == 2)
			{
				//D3DXVec2Lerp(&m_pos, &m_pos, &Vec2(curPos.x, m_pos.y), 0.04);
				Pattern3T = new cTimer(20, [&]() {
					pattern3 = true;
					count = 0;
					Pattern3T = nullptr;
					});
				m_pos.x = curPos.x;
				pattern3 = false;
			}
		}
	}
}