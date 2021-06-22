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

	INPUT->lDown = false;
	INPUT->lUp = false;

	SOUND->StopAll();
	SOUND->Play("b", true);
}

void cTitleScene::Update()
{
	if (INPUT->lDown)
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 0.7))
		{
			bGameStart = true;
		}
		else
		{
			bGameStart = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
		{
			bGameQuit = true;
		}
		else
		{
			bGameQuit = false;
		}
		downPos = INPUT->GetMousePos();
		INPUT->lDown = false;
	}
	else if (INPUT->lUp)
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 0.7))
		{
			if (coll->CheckCollision(downPos, Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 0.7))
			{
				SCENE->ChangeScene("cIngameScene");
			}
		}
		else
		{
			bGameStart = false;
			bStartBtnOver = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
		{
			if (coll->CheckCollision(downPos, Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
			{
				exit(0);
			}
		}
		else
		{
			bGameQuit = false;
			bQuitBtnOver = false;
		}
		INPUT->lUp = false;
	}
	else
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 0.7))
		{
			bStartBtnOver = true;
		}
		else
		{
			bStartBtnOver = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
		{
			bQuitBtnOver = true;
		}
		else
		{
			bQuitBtnOver = false;
		}
	}
}

void cTitleScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, 200));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2));

	if (bGameStart)
		RENDER->CenterRender(IMAGE->FindImage("StartButtonPressed"), Vec2(WINSIZEX / 2 - 300, 700), 0.7);
	else if (bStartBtnOver)
		RENDER->CenterRender(IMAGE->FindImage("StartButtonHighlight"), Vec2(WINSIZEX / 2 - 300, 700), 0.7);
	else
		RENDER->CenterRender(IMAGE->FindImage("StartButton"), Vec2(WINSIZEX / 2 - 300, 700), 0.7);

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