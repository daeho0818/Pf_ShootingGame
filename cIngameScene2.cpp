#include "DXUT.h"
#include "cIngameScene2.h"

cIngameScene2::cIngameScene2()
{
}
cIngameScene2::~cIngameScene2()
{
	Release();
}

void cIngameScene2::Init()
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

void cIngameScene2::Update()
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

void cIngameScene2::Render()
{
	map->Render();
	player->Render();
	mob->Render();
	bullet->Render();
	item->Render();
}

void cIngameScene2::UIRender()
{
	player->UIRender();
	mob->UIRender();
	if (pos_x >= -50) UI->PrintText("STAGE 2", Vec2(pos_x, 50), 50);
}

void cIngameScene2::Release()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(map);
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(mob);
	SAFE_DELETE(coll);
	SAFE_DELETE(item);
}

void cIngameScene2::PlayerSkill()
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

void cIngameScene2::SceneChange()
{
	if (mob->bossD)
	{
		SCENE->mobCount = 0;
		SCENE->stage = 0;
		SCENE->bossCount = 0;
		SCENE->gameClear = true;
		SCENE->ChangeScene("cEndingScene");
	}

	if (player->m_Hp <= 0)
	{
		SCENE->mobCount = 0;
		SCENE->stage = 0;
		SCENE->bossCount = 0;
		SCENE->gameClear = false;
		SOUND->Play("explosion");
		SCENE->ChangeScene("cEndingScene");
	}
}

void cIngameScene2::PrintStageTxt()
{
	if (left) pos_x -= 2; else if (right) pos_x += 2;

	if (pos_x > 200)
	{
		if (right) AS = new cTimer(2, [&]()->void {left = true; AS = nullptr; });
		right = false;
	}
}