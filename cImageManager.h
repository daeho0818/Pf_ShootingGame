#pragma once
#include "singleton.h"
class cImageManager :
	public singleton<cImageManager>
{
	map<string, cTexture*> m_images;
public:
	cImageManager();
	// ~cImageManager() : cImageManager의 객체가 소멸할 때 불리는 함수 (소멸자)
	~cImageManager();
	// AddImage(const string& key, const string& path, int count) : 이미지를 파일로부터 찾아와 로드하는 함수 
	void AddImage(const string& key, const string& path, int count = 0); // key : 개발 중 쓸 이름, path : 저장된 이미지 이름, count : 갯수
	// FindImage(const string& key) : m_images에 저장한 이미지를 찾는 함수
	cTexture* FindImage(const string& key);
	// MakeVecImg(const string& key) : 여러 장의 사진들을 애니메이션화 하는 함수
	vector<cTexture*> MakeVecImg(const string& key);
};

#define IMAGE cImageManager::GetInstance()