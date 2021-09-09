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
	bcoll = new cButtonCollision();
	lobbyButton = new cButton(IMAGE->FindImage("LobbyButton"), Vec2(WINSIZEX / 2 - 300, 600), 2, [&]()->void {SCENE->ChangeScene("cTitleScene"); });
	lobbyButton->InitImgs(IMAGE->FindImage("LobbyButton"), IMAGE->FindImage("LobbyButtonHighlight"), IMAGE->FindImage("LobbyButtonPressed"));
	bcoll->AddButton(lobbyButton);

	quitButton = new cButton(IMAGE->FindImage("QuitButton"), Vec2(WINSIZEX / 2 - 300, 1000), 2, [&]()->void {exit(0); });
	quitButton->InitImgs(IMAGE->FindImage("QuitButton"), IMAGE->FindImage("QuitButtonHighlight"), IMAGE->FindImage("QuitButtonPressed"));
	bcoll->AddButton(quitButton);
}

void cEndingScene::Update()
{
	bcoll->ChkCollision(INPUT->GetMousePos());
}

void cEndingScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, 200));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(WINSIZEX / 2, WINSIZEY / 2));

	bcoll->Render();
}

void cEndingScene::UIRender()
{
}

void cEndingScene::Release()
{
	SAFE_DELETE(bcoll);
	SAFE_DELETE(lobbyButton);
	SAFE_DELETE(quitButton);
}