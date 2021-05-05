#pragma once
#include "cBullet.h"
#include "cPlayer.h"
#include "cItemAdmin.h"
#include "cItem.h"
#include "cMob.h"
class cCollision
{
public:
	cCollision(vector<cBullet*> &bullet, vector<cMob*> &m_mob, cPlayer* player, cItemAdmin* itemAd);
	~cCollision();

	vector<cBullet*>& m_bullet;
	vector<cMob*>& m_mob;
	cPlayer* m_player;
	cItemAdmin* m_itemAd;
	vector<cItem*>& m_item;

	int partSize = 4;
	bool b_PMcoll = true;

	void Update();

	void MPColl(); // ¸÷ ÇÃ·¹ÀÌ¾î'
	void MPBColl(); // ¸÷ ÇÃ·¹ÀÌ¾î ÃÑ¾Ë
	void MBPColl(); // ¸ö ÃÑ¾Ë ÇÃ·¹ÀÌ¾î
	void IPColl();
};