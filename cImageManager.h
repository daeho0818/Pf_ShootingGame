#pragma once
#include "singleton.h"
class cImageManager :
	public singleton<cImageManager>
{
	map<string, cTexture*> m_images;
public:
	cImageManager();
	// ~cImageManager() : cImageManager�� ��ü�� �Ҹ��� �� �Ҹ��� �Լ� (�Ҹ���)
	~cImageManager();
	// AddImage(const string& key, const string& path, int count) : �̹����� ���Ϸκ��� ã�ƿ� �ε��ϴ� �Լ� 
	void AddImage(const string& key, const string& path, int count = 0); // key : ���� �� �� �̸�, path : ����� �̹��� �̸�, count : ����
	// FindImage(const string& key) : m_images�� ������ �̹����� ã�� �Լ�
	cTexture* FindImage(const string& key);
	// MakeVecImg(const string& key) : ���� ���� �������� �ִϸ��̼�ȭ �ϴ� �Լ�
	vector<cTexture*> MakeVecImg(const string& key);
};

#define IMAGE cImageManager::GetInstance()