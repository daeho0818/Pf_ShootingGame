#include "DXUT.h"
#include "cSceneManager.h"

cSceneManager::cSceneManager() 
{
	PlayerInit();
}
cSceneManager::~cSceneManager()
{
	Release();
}

void cSceneManager::Update()
{
	if (nowScene) nowScene->Update();
	if (nextScene)
	{
		if (nowScene) nowScene->Release();
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	if (INPUT->KeyDown(32)) mobCount += 15;
}

void cSceneManager::Render()
{
	if (nowScene) nowScene->Render();
}

void cSceneManager::UIRender()
{
	if (nowScene) nowScene->UIRender();
}

void cSceneManager::Release()
{
	if (nowScene) nowScene->Release();
	for (auto iter : m_scenes) SAFE_DELETE(iter.second);
	m_scenes.clear();
}

void cSceneManager::AddScene(string key, cScene* scene)
{
	m_scenes.insert(make_pair(key, scene));
}

void cSceneManager::ChangeScene(string key)
{
	auto find = m_scenes.find(key);
	nextScene = find->second;
}

void cSceneManager::PlayerInit()
{
	m_Hp = 6;
	multiDir = false;
}