#include "DXUT.h"
#include "cEndingScene.h"

cEndingScene::cEndingScene()
{
}

cEndingScene::~cEndingScene()
{
}

void cEndingScene::Init()
{
}

void cEndingScene::Update()
{
	if (INPUT->KeyDown(VK_LEFT))
	{
		bTitle = true;
		bExit = false;
	}
	else if (INPUT->KeyDown(VK_RIGHT))
	{
		bExit = true;
		bTitle = false;
	}
	if (INPUT->KeyDown(13))
	{
		if (bTitle)
			SCENE->ChangeScene("cTitleScene");
		if (bExit)
			exit(0);
	}
}

void cEndingScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, 200));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
}

void cEndingScene::UIRender()
{
	string text;
	if (SCENE->gameClear) text = "Game Clear!";
	if (!SCENE->gameClear) text = "Game Over..";
	UI->PrintText(text, Vec2(WINSIZEX / 2, 400), 100);
	if (bTitle)
		UI->CenterRender(IMAGE->FindImage("Title_y"), Vec2(WINSIZEX / 4, 700));
	else
		UI->CenterRender(IMAGE->FindImage("Title_w"), Vec2(WINSIZEX / 4, 700));
	if (bExit)
		UI->CenterRender(IMAGE->FindImage("Exit_y"), Vec2(WINSIZEX / 4 * 3 - 100, 700));
	else
		UI->CenterRender(IMAGE->FindImage("Exit_w"), Vec2(WINSIZEX / 4 * 3 - 100, 700));
}

void cEndingScene::Release()
{
}