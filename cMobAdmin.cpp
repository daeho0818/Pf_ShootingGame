#include "DXUT.h"
#include "cMobAdmin.h"
#include "cBalloon.h"
#include "cSideMove.h"
#include "cRifle.h"
#include "cBoss.h"

cMobAdmin::cMobAdmin(cPlayer* player, vector<cBullet*>& bullet)
	:m_player(player), m_bullet(bullet)
{
}

cMobAdmin::~cMobAdmin()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(BalT);
	SAFE_DELETE(SideT);
	SAFE_DELETE(RifleT);
	for (auto iter : m_mobs) SAFE_DELETE(iter);
	m_mobs.clear();
}

void cMobAdmin::Update()
{
	for (auto iter : m_mobs) iter->Update();
	CreateMob();
	IsOut();
	IsDestroy();
}

void cMobAdmin::Render()
{
	for (auto iter : m_mobs)iter->Render();
}

void cMobAdmin::UIRender()
{
	for (auto iter : m_mobs) iter->UIRender();
}

void cMobAdmin::CreateMob()
{
	if (AS != nullptr) AS->Update();
	if (BalT != nullptr) BalT->Update();
	if (SideT != nullptr) SideT->Update();
	if (RifleT != nullptr) RifleT->Update();

	if (SCENE->mobCount >= 30)
	{
		if (boss)
		{
			m_mobs.push_back(new cBoss(Vec2(600, -100), m_player, m_bullet, 1));
			m_mobs.push_back(new cBoss(Vec2(1000, -100), m_player, m_bullet, 2));
			boss = false;
		}
		if (Side)
		{
			SideT = new cTimer(6, [&]()->void {Side = true; SideT = nullptr; });
			m_mobs.push_back(new cSideMove(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Side = false;
		}
		if (Bal)
		{
			BalT = new cTimer(4, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBalloon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
		if (Rifle && SCENE->stage == 2)
		{
			RifleT = new cTimer(7, [&]()->void {Rifle = true; RifleT = nullptr; });
			m_mobs.push_back(new cRifle(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Rifle = false;
		}
	}

	else if (SCENE->mobCount >= 15 && SCENE->stage == 1)
	{
		if (Side)
		{
			SideT = new cTimer(4, [&]()->void {Side = true; SideT = nullptr; });
			m_mobs.push_back(new cSideMove(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Side = false;
		}
		if (Bal)
		{
			BalT = new cTimer(3, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBalloon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
		if (Rifle)
		{
			RifleT = new cTimer(7, [&]()->void {Rifle = true; RifleT = nullptr; });
			m_mobs.push_back(new cRifle(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Rifle = false;
		}
	}	
	
	else if (SCENE->mobCount >= 15 && SCENE->stage == 0)
	{
		if (boss)
		{
			m_mobs.push_back(new cBoss(Vec2(WINSIZEX / 2, -100), m_player, m_bullet));
			boss = false;
		}
		if (Side)
		{
			SideT = new cTimer(6, [&]()->void {Side = true; SideT = nullptr; });
			m_mobs.push_back(new cSideMove(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Side = false;
		}
		if (Bal)
		{
			BalT = new cTimer(4, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBalloon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
		if (Rifle)
		{
			RifleT = new cTimer(7, [&]()->void {Rifle = true; RifleT = nullptr; });
			m_mobs.push_back(new cRifle(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Rifle = false;
		}
	}

	else
	{
		if (Side)
		{
			SideT = new cTimer(3, [&]()->void {Side = true; SideT = nullptr; });
			m_mobs.push_back(new cSideMove(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Side = false;
		}
		if (Bal)
		{
			BalT = new cTimer(1, [&]()->void {Bal = true; BalT = nullptr; });
			m_mobs.push_back(new cBalloon(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Bal = false;
		}
		if (Rifle && SCENE->stage == 1)
		{
			RifleT = new cTimer(5, [&]()->void {Rifle = true; RifleT = nullptr; });
			m_mobs.push_back(new cRifle(Vec2(rand() % 1320 + 300, -100), m_player, m_bullet));
			Rifle = false;
		}
	}
}

void cMobAdmin::IsOut()
{
	for (auto& iter = m_mobs.begin(); iter != m_mobs.end();)
	{
		if ((*iter)->IsOutMap() && (*iter)->mobType != "Boss")
		{
			SAFE_DELETE(*iter);
			iter = m_mobs.erase(iter);
		}
		else
			iter++;
	}
}

void cMobAdmin::IsDestroy()
{
	int PartSize = 5;

	for (auto& iter = m_mobs.begin(); iter != m_mobs.end();)
	{
		if ((*iter)->isDestroy)
		{
			SCENE->mobCount++;
			if ((*iter)->mobType == "Boss")
			{
				SCENE->bossCount++;
				SCENE->multiDir = true;
				if (SCENE->bossCount == 1)
					AS = new cTimer(3, [&]()->void {SCENE->stage = 1; AS = nullptr; });
				if (SCENE->bossCount == 3)
				{
					AS = new cTimer(3, [&]()->void {
						bossD = true; SCENE->stage = 3; AS = nullptr; });
				}
				PartSize = 10;
				int random = rand() % 100;
				PART->AddParticle(Vec2((*iter)->m_pos.x + random,
					(*iter)->m_pos.y - random), PartSize, 1, 0.02);
				random = rand() % 100;
				PART->AddParticle(Vec2((*iter)->m_pos.x - random,
					(*iter)->m_pos.y + random), PartSize, 1, 0.05);
				random = rand() % 100;
				PART->AddParticle(Vec2((*iter)->m_pos.x - random,
					(*iter)->m_pos.y + random), PartSize, 1, 0.1);
			}
			PART->AddParticle((*iter)->m_pos, PartSize, 1);
			SOUND->Play("explosion");
			SAFE_DELETE(*iter);
			iter = m_mobs.erase(iter);
		}
		else
			iter++;
	}
}