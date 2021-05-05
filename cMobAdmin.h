#pragma once
#include "cMob.h"
#include "cPlayer.h"
#include "cBullet.h"
class cMobAdmin
{
public:
	cMobAdmin(cPlayer* player, vector<cBullet*>& bullet);
	~cMobAdmin();

	vector<cMob*> m_mobs;

	cPlayer* m_player;
	vector<cBullet*>& m_bullet;

	cTimer* AS = nullptr;
	cTimer* BalT = nullptr;
	cTimer* SideT = nullptr;
	cTimer* RifleT = nullptr;
	bool Bal = true;
	bool Side = true;
	bool Rifle = true;
	bool boss = true;
	bool bossAlive = false;
	bool bossD = false;
	
	void Update();
	void Render();
	void UIRender();

	void CreateMob();
	void IsOut();
	void IsDestroy();
};