#include "DXUT.h"
#include "cTitleScene.h"

cTitleScene::cTitleScene()
{
}

cTitleScene::~cTitleScene()
{
	Release();
}

void cTitleScene::Init()
{
	SCENE->PlayerInit();
	SCENE->mobCount = 0;
	SOUND->StopAll();
	SOUND->Play("b", true);
}

void cTitleScene::Update()
{
	if (INPUT->KeyDown(VK_LEFT))
	{
		bGameStart = true;
		bExit = false;
	}
	else if (INPUT->KeyDown(VK_RIGHT))
	{
		bExit = true;
		bGameStart = false;
	}
	if (INPUT->KeyDown(13))
	{
		if(bGameStart)
			SCENE->ChangeScene("cIngameScene");
		if (bExit)
			exit(0);
	}
}

void cTitleScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, 200));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
}

void cTitleScene::UIRender()
{
	if(bGameStart)
		UI->CenterRender(IMAGE->FindImage("GameStart_y"), Vec2(WINSIZEX / 4, 700));
	else
		UI->CenterRender(IMAGE->FindImage("GameStart_w"), Vec2(WINSIZEX / 4, 700));
	if(bExit)
		UI->CenterRender(IMAGE->FindImage("Exit_y"), Vec2(WINSIZEX / 4 * 3 - 100, 700));
	else
		UI->CenterRender(IMAGE->FindImage("Exit_w"), Vec2(WINSIZEX / 4 * 3 - 100, 700));
}

void cTitleScene::Release()
{
}