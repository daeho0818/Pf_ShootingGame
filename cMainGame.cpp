#include "DXUT.h"
#include "cMainGame.h"
#include "cIngameScene.h"
#include "cIngameScene2.h"
#include "cTitleScene.h"
#include "cEndingScene.h"

cMainGame::cMainGame()
{
}
cMainGame::~cMainGame()
{
}

void cMainGame::Init() 
{
	SCENE->AddScene("cIngameScene",  new cIngameScene); // cIngameScene�̶�� �� �ε�
	SCENE->AddScene("cIngameScene2",  new cIngameScene2); // cIngameScene2�̶�� �� �ε�
	SCENE->AddScene("cTitleScene", new cTitleScene); // cTitleScene�̶�� �� �ε�
	SCENE->AddScene("cEndingScene", new cEndingScene); // cEndingScene�̶�� �� �ε�
	AddResource(); // ���Ϸκ��� ��� �������� �ε��ϴ� �Լ�
	SCENE->ChangeScene("cTitleScene"); // cTitleScene�̶�� �� �ҷ�����
}

void cMainGame::Update()
{
	INPUT->Update(); // � Ű���尡 ���ȴ��� �˻�
	SCENE->Update(); // ���� ���� Update() �Լ��� �����ϰų� ���� ������ ����� �ÿ� ������ �ʱ�ȭ ���ִ� ���� ������ ���ִ� �Լ�
	PART->Update();
	SOUND->Update();
}

void cMainGame::Render()
{
	SCENE->Render();
	PART->Render();
	UI->Begin();
	SCENE->UIRender();
	UI->End();
}

void cMainGame::Release()
{
	cImageManager::ReleaseInstance();
	cInputManager::ReleaseInstance();
	cParticleManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cSoundManager::ReleaseInstance();
	cUIManager::ReleaseInstance();
	cRenderManager::ReleaseInstance();
}

void cMainGame::LostDevice()
{
	UI->Lost();
}

void cMainGame::ResetDevice()
{
	UI->Reset();
}

void cMainGame::AddResource()
{
	IMAGE->AddImage("stage_1_BG", "stage_1_BG");
	IMAGE->AddImage("stage_2_BG", "stage_2_BG");
	IMAGE->AddImage("stage_3_BG", "stage_3_BG");
	IMAGE->AddImage("player", "player");
	IMAGE->AddImage("Hp", "Hp");
	IMAGE->AddImage("SkillPoint", "SkillPoint");
	IMAGE->AddImage("Hp+", "Hp+");
	IMAGE->AddImage("bullet_enemy", "bullet_enemy");
	IMAGE->AddImage("bullet_player", "bullet_player");
	IMAGE->AddImage("Title_BG", "/title/BG");
	IMAGE->AddImage("Title_BG_Cloud", "/title/BG_Cloud");
	IMAGE->AddImage("Title_BG_Mountains", "/title/BG_Mountains");
	IMAGE->AddImage("Title_BG_Moon", "/title/BG_Moon");
	IMAGE->AddImage("GameStart_w", "/title/GameStart_w");
	IMAGE->AddImage("GameStart_y", "/title/GameStart_y");
	IMAGE->AddImage("Exit_w", "/title/Exit_w");
	IMAGE->AddImage("Exit_y", "/title/Exit_y");
	IMAGE->AddImage("Title_w", "/title/Title_w");
	IMAGE->AddImage("Title_y", "/title/Title_y");
	IMAGE->AddImage("mob_1", "mob1/mob_1");
	IMAGE->AddImage("mob_2", "mob2/mob_2");
	IMAGE->AddImage("mob_3", "mob3/mob_3");
	IMAGE->AddImage("boss", "boss/boss");

	IMAGE->AddImage("expl_mob","effect/mob/expl_mob", 10);
	IMAGE->AddImage("expl_player", "effect/player/expl_player", 10);
	IMAGE->AddImage("skill_effect", "skill/SkillEffect", 20);

	SOUND->AddSound("gun_fire", L"gun_fire");
	SOUND->AddSound("explosion", L"explosion");
	SOUND->AddSound("playerHurt", L"playerHurt");
	SOUND->AddSound("heal", L"heal");
	SOUND->AddSound("b", L"BackGround");
}