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

	cloud_oper_value[0] = mountains_oper_value[0] = WINSIZEX / 2;
	cloud_oper_value[1] = mountains_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;

	playerPos = { WINSIZEX + 50, WINSIZEY / 2 };
}

void cTitleScene::Update()
{
	playerPos = *D3DXVec2Lerp(&playerPos, &playerPos, &Vec2(WINSIZEX / 2, WINSIZEY / 2), Delta * 2);

	if (INPUT->LButtonDown())
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 2))
			bGameStart = true;
		else
			bGameStart = false;

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
			bGameQuit = true;
		else
			bGameQuit = false;
		downPos = INPUT->GetMousePos();
	}
	else if (INPUT->LButtonUp())
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 2))
		{
			if (coll->CheckCollision(downPos, Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 2))
				SCENE->ChangeScene("cIngameScene");
		}
		else
		{
			bGameStart = false;
			bStartBtnOver = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
		{
			if (coll->CheckCollision(downPos, Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
				exit(0);
		}
		else
		{
			bGameQuit = false;
			bQuitBtnOver = false;
		}
	}
	else
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 2))
			bStartBtnOver = true;
		else
			bStartBtnOver = false;

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
			bQuitBtnOver = true;
		else
			bQuitBtnOver = false;
	}

	if (moon_oper_value > 90) isMoonUp = false;
	else if (moon_oper_value < -90) isMoonUp = true;

	if (!isMoonUp)
		moon_oper_value--;
	else
		moon_oper_value++;

	cloud_oper_value[0] += 10;
	cloud_oper_value[1] += 10;

	mountains_oper_value[0] ++;
	mountains_oper_value[1] ++;

	if (cloud_oper_value[0] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Cloud")->info.Width / 2))
		cloud_oper_value[0] = (WINSIZEX / 2) - WINSIZEX;
	if (cloud_oper_value[1] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Cloud")->info.Width / 2))
		cloud_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;

	if (mountains_oper_value[0] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Mountains")->info.Width / 2))
		mountains_oper_value[0] = (WINSIZEX / 2) - WINSIZEX;
	if (mountains_oper_value[1] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Mountains")->info.Width / 2))
		mountains_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;
}

void cTitleScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(mountains_oper_value[0], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(mountains_oper_value[1], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, sin(moon_oper_value * D3DX_PI / 180) * 50));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[0], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[0] * 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[1], WINSIZEY / 2));

	RENDER->CenterRender(IMAGE->FindImage("player"), playerPos, 0.5f, 90 * D3DX_PI / 180);

	if (bGameStart)
		RENDER->CenterRender(IMAGE->FindImage("StartButtonPressed"), Vec2(WINSIZEX / 2 - 300, 700), 2);
	else if (bStartBtnOver)
		RENDER->CenterRender(IMAGE->FindImage("StartButtonHighlight"), Vec2(WINSIZEX / 2 - 300, 700), 2);
	else
		RENDER->CenterRender(IMAGE->FindImage("StartButton"), Vec2(WINSIZEX / 2 - 300, 700), 2);

	if (bGameQuit)
		RENDER->CenterRender(IMAGE->FindImage("QuitButtonPressed"), Vec2(WINSIZEX / 2 + 300, 700), 0.7);
	else if (bQuitBtnOver)
		RENDER->CenterRender(IMAGE->FindImage("QuitButtonHighlight"), Vec2(WINSIZEX / 2 + 300, 700), 0.7);
	else
		RENDER->CenterRender(IMAGE->FindImage("QuitButton"), Vec2(WINSIZEX / 2 + 300, 700), 0.7);

	RENDER->CenterRender(IMAGE->FindImage("GameName"), Vec2(WINSIZEX / 2, 300));
}

void cTitleScene::UIRender()
{
}

void cTitleScene::Release()
{
}