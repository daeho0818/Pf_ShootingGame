#include "DXUT.h"
#include "cIngameScene.h"

cIngameScene::cIngameScene()
{
}
cIngameScene::~cIngameScene()
{
	Release();
}

void cIngameScene::Init()
{
	left = false; right = true; pos_x = 0;
	srand(time(NULL));
	map = new cScrollMap();
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->m_bullets);
	mob = new cMobAdmin(player, bullet->m_bullets);
	item = new cItemAdmin(player);
	coll = new cCollision(bullet->m_bullets, mob->m_mobs, player, item);
}

void cIngameScene::Update()
{
	if (AS != nullptr) AS->Update();

	PrintStageTxt();
	PlayerSkill();
	SceneChange();
	map->Update(50);
	player->Update();
	mob->Update();
	bullet->Update();
	coll->Update();
	item->Update();
}

void cIngameScene::Render()
{
	map->Render();
	player->Render();
	mob->Render();
	bullet->Render();
	item->Render();
}

void cIngameScene::UIRender()
{
	player->UIRender();
	mob->UIRender();
	if(pos_x >= -50) UI->PrintText("STAGE 1", Vec2(pos_x, 50), 50);
}

void cIngameScene::Release()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(map);
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(mob);
	SAFE_DELETE(coll);
	SAFE_DELETE(item);
}

void cIngameScene::PlayerSkill()
{
	if (player->playerSkill) if (INPUT->KeyDown(88))
	{
		PART->AddParticle(player->m_pos, 50, 2);
		for (auto iter : mob->m_bullet) SAFE_DELETE(iter);
		mob->m_bullet.clear();
		player->skillPoint = 0;
		player->playerSkill = false;
	}
}

void cIngameScene::SceneChange()
{
	if (SCENE->stage == 1)
	{
		SCENE->stage = 2;
		SCENE->ChangeScene("cIngameScene2");
	}
	if (player->m_Hp <= 0)
	{
		SCENE->mobCount = 0;
		SCENE->stage = 0;
		SCENE->bossCount = 0;
		SCENE->gameClear = false;
		SCENE->ChangeScene("cEndingScene");
	}
}

void cIngameScene::PrintStageTxt()
{
	if (left) pos_x -= 2; else if (right) pos_x += 2;

	if (pos_x > 200)
	{
		if (right) AS = new cTimer(2, [&]()->void {left = true; AS = nullptr; });
		right = false;
	}
}