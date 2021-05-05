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

	void MPColl(); // �� �÷��̾�'
	void MPBColl(); // �� �÷��̾� �Ѿ�
	void MBPColl(); // �� �Ѿ� �÷��̾�
	void IPColl();
};