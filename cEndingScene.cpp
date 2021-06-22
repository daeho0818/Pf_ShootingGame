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
	if (INPUT->lDown)
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("StartButton"), 0.7))
		{
			bTitle = true;
		}
		else
		{
			bTitle = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
		{
			bExit = true;
		}
		else
		{
			bExit = false;
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
				SCENE->ChangeScene("cTitleScene");
			}
		}
		else
		{
			bTitle = false;
			bTitleBtnOver = false;
		}

		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("LobbyButton"), 0.7))
		{
			if (coll->CheckCollision(downPos, Vec2(WINSIZEX / 2 + 300, 700), IMAGE->FindImage("QuitButton"), 0.7))
			{
				exit(0);
			}
		}
		else
		{
			bExit = false;
			bQuitBtnOver = false;
		}
		INPUT->lUp = false;
	}
	else
	{
		if (coll->CheckCollision(INPUT->GetMousePos(), Vec2(WINSIZEX / 2 - 300, 700), IMAGE->FindImage("LobbyButton"), 0.7))
		{
			bTitleBtnOver = true;
		}
		else
		{
			bTitleBtnOver = false;
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

void cEndingScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, 200));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2));

	if (bTitle)
		RENDER->CenterRender(IMAGE->FindImage("LobbyButtonPressed"), Vec2(WINSIZEX / 2 - 300, 700), 0.7);
	else
		RENDER->CenterRender(IMAGE->FindImage("LobbyButton"), Vec2(WINSIZEX / 2 - 300, 700), 0.7);
	if (bExit)
		RENDER->CenterRender(IMAGE->FindImage("QuitButtonPressed"), Vec2(WINSIZEX / 2 + 300, 700), 0.7);
	else
		RENDER->CenterRender(IMAGE->FindImage("QuitButton"), Vec2(WINSIZEX / 2 + 300, 700), 0.7);
}

void cEndingScene::UIRender()
{
}

void cEndingScene::Release()
{
}