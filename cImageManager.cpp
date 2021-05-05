#include "DXUT.h"
#include "cImageManager.h"

cImageManager::cImageManager() 
{
}

cImageManager::~cImageManager()
{
	for (auto iter : m_images) // m_images의 모든 요소를 도는 for문
	{
		iter.second->ptr->Release(); // m_images의 texture의 텍스쳐의 데이터를 제거
		SAFE_DELETE(iter.second); // m_images의 texture 메모리 해제
	}
	m_images.clear(); // m_images의 모든 요소 제거
}

void cImageManager::AddImage(const string& key, const string& path, int count)
{
	auto find = m_images.find(key); // map 자료구조를 통해 m_images 안에 key라는 이미지가 있는지 찾고 find에 넣음
	char Path[128]; // 저장 경로 저장할 변수
	if (count == 0) // 사진 갯수를 정해주지 않았다면 (1개)
	{
		sprintf(Path, "./Resource/Image/%s.png", path.c_str()); // 입력받은 path를 통해 저장 경로를 완성 후 Path에 대입
		if (find == m_images.end()) // 찾은 find가 m_images의 마지막이라면
		{
			LPDIRECT3DTEXTURE9 ptr; // 이미지 저장할 구조체
			D3DXIMAGE_INFO info; // 이미지 정보 저장할 구조체
			//D3DXCreateTextureFromFileExA() : 텍스쳐를 생성하는 함수
			if (D3DXCreateTextureFromFileExA(g_device, Path, -2, -2, 0, 0,
				D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &ptr) == S_OK) // 성공적으로 생성됐다면
			{
				cTexture* texture = new cTexture(ptr, info); // texture : cTexture 형태로, 이미지와 이미지 정보를 담은 변수
				// insert(make_pair(key, value)) : 맵에 key와 value의 두 값을 동시에 저장해 추가
				m_images.insert(make_pair(key, texture));
			}
		}
	}
	else // 사진이 여러장일 경우
	{
		char Key[128]; // 뒤에 숫자를 붙인 이름을 저장할 변수
		for (int i = 0; i < count; i++) // 사진 장수만큼
		{
			sprintf(Path, "./Resource/Image/%s (%d).png", path.c_str(), i); // 입력받은 path와 i를 통해 저장 경로 완성 후 Path에 대입
			sprintf(Key, "%s%d", key.c_str(), i); // key 뒤에 숫자를 붙인 개발 중 쓸 이름을 Key에 대입
			if (find == m_images.end()) // 찾은 find가 m_images의 마지막이라면
			{
				LPDIRECT3DTEXTURE9 ptr; // 이미지 저장할 구조체
				D3DXIMAGE_INFO info; // 이미지 정보 저장할 구조체
				//D3DXCreateTextureFromFileExA() : 텍스쳐를 생성하는 함수
				if (D3DXCreateTextureFromFileExA(g_device, Path, -2, -2, 0, 0,
					D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &ptr) == S_OK) // 성공적으로 생성됐다면
				{
					cTexture* texture = new cTexture(ptr, info); // texture : cTextrue 형태로, 이미지와 이미지 정보를 담은 변수
					// insert(make_pair(key, value)) : 맵에 Key와 value의 두 값을 동시에 저장해 추가
					m_images.insert(make_pair(Key, texture));
				}
			}
		}
	}
}

cTexture* cImageManager::FindImage(const string& key)
{
	// find(key) : map 내에서 key라는 이름의 요소를 찾는 함수
	auto find = m_images.find(key); // 입력받은 key라는 이름이 m_images 안에 있는지 찾고 find에 대입
	if (find == m_images.end()) return nullptr; // 찾은 find가 m_images의 마지막 요소라면 nullptr 반환
	return find->second; // key와 함께 저장했던 다른 요소를 반환
}

vector<cTexture*> cImageManager::MakeVecImg(const string& key)
{
	vector<cTexture*> m_vecimg; // m_vecimg : 여러 이미지들을 담을 벡터
	for (int i = 0; ; i++) // 이미지의 갯수가 몇 장인지 모르기 때문에 반복 횟수 명시 X
	{
		char Key[128]; // 개발자가 저장한 이름을 찾기 위한 변수
		sprintf(Key, "%s%d", key.c_str(), i); // key라는 이름 뒤에 i라는 숫자가 붇은 이름을 Key에 저장
		auto find = FindImage(Key); // Key라는 이름의 이미지를 찾고 find에 대입
		if (find == nullptr) break; // find가 nullptr일 때 반복문 종료
		m_vecimg.push_back(find); // m_vecimg에 찾은 find를 추가
	}
	return m_vecimg; // 여러 이미지들이 담긴 벡터 m_vecimg 반환
}