#pragma once
#include "2. Manager/singleton.h"
class cSceneManager 
	:public singleton<cSceneManager>
{
public:
	map<string, cScene*> m_scenes;
	cScene* nowScene = nullptr;
	cScene* nextScene = nullptr;

	cSceneManager();
	~cSceneManager();

	float m_Hp;
	int mobCount = 0;
	int stage = 0;
	int bossCount = 0;
	bool gameClear;

	void Update();
	void Render();
	void UIRender();
	void Release();

	void AddScene(string key, cScene* scene);
	void ChangeScene(string key);

	void PlayerInit();
};

#define SCENE cSceneManager::GetInstance()