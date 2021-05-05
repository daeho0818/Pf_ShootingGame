#include "DXUT.h"
#include "cImageManager.h"

cImageManager::cImageManager() 
{
}

cImageManager::~cImageManager()
{
	for (auto iter : m_images) // m_images�� ��� ��Ҹ� ���� for��
	{
		iter.second->ptr->Release(); // m_images�� texture�� �ؽ����� �����͸� ����
		SAFE_DELETE(iter.second); // m_images�� texture �޸� ����
	}
	m_images.clear(); // m_images�� ��� ��� ����
}

void cImageManager::AddImage(const string& key, const string& path, int count)
{
	auto find = m_images.find(key); // map �ڷᱸ���� ���� m_images �ȿ� key��� �̹����� �ִ��� ã�� find�� ����
	char Path[128]; // ���� ��� ������ ����
	if (count == 0) // ���� ������ �������� �ʾҴٸ� (1��)
	{
		sprintf(Path, "./Resource/Image/%s.png", path.c_str()); // �Է¹��� path�� ���� ���� ��θ� �ϼ� �� Path�� ����
		if (find == m_images.end()) // ã�� find�� m_images�� �������̶��
		{
			LPDIRECT3DTEXTURE9 ptr; // �̹��� ������ ����ü
			D3DXIMAGE_INFO info; // �̹��� ���� ������ ����ü
			//D3DXCreateTextureFromFileExA() : �ؽ��ĸ� �����ϴ� �Լ�
			if (D3DXCreateTextureFromFileExA(g_device, Path, -2, -2, 0, 0,
				D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &ptr) == S_OK) // ���������� �����ƴٸ�
			{
				cTexture* texture = new cTexture(ptr, info); // texture : cTexture ���·�, �̹����� �̹��� ������ ���� ����
				// insert(make_pair(key, value)) : �ʿ� key�� value�� �� ���� ���ÿ� ������ �߰�
				m_images.insert(make_pair(key, texture));
			}
		}
	}
	else // ������ �������� ���
	{
		char Key[128]; // �ڿ� ���ڸ� ���� �̸��� ������ ����
		for (int i = 0; i < count; i++) // ���� �����ŭ
		{
			sprintf(Path, "./Resource/Image/%s (%d).png", path.c_str(), i); // �Է¹��� path�� i�� ���� ���� ��� �ϼ� �� Path�� ����
			sprintf(Key, "%s%d", key.c_str(), i); // key �ڿ� ���ڸ� ���� ���� �� �� �̸��� Key�� ����
			if (find == m_images.end()) // ã�� find�� m_images�� �������̶��
			{
				LPDIRECT3DTEXTURE9 ptr; // �̹��� ������ ����ü
				D3DXIMAGE_INFO info; // �̹��� ���� ������ ����ü
				//D3DXCreateTextureFromFileExA() : �ؽ��ĸ� �����ϴ� �Լ�
				if (D3DXCreateTextureFromFileExA(g_device, Path, -2, -2, 0, 0,
					D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &ptr) == S_OK) // ���������� �����ƴٸ�
				{
					cTexture* texture = new cTexture(ptr, info); // texture : cTextrue ���·�, �̹����� �̹��� ������ ���� ����
					// insert(make_pair(key, value)) : �ʿ� Key�� value�� �� ���� ���ÿ� ������ �߰�
					m_images.insert(make_pair(Key, texture));
				}
			}
		}
	}
}

cTexture* cImageManager::FindImage(const string& key)
{
	// find(key) : map ������ key��� �̸��� ��Ҹ� ã�� �Լ�
	auto find = m_images.find(key); // �Է¹��� key��� �̸��� m_images �ȿ� �ִ��� ã�� find�� ����
	if (find == m_images.end()) return nullptr; // ã�� find�� m_images�� ������ ��Ҷ�� nullptr ��ȯ
	return find->second; // key�� �Բ� �����ߴ� �ٸ� ��Ҹ� ��ȯ
}

vector<cTexture*> cImageManager::MakeVecImg(const string& key)
{
	vector<cTexture*> m_vecimg; // m_vecimg : ���� �̹������� ���� ����
	for (int i = 0; ; i++) // �̹����� ������ �� ������ �𸣱� ������ �ݺ� Ƚ�� ��� X
	{
		char Key[128]; // �����ڰ� ������ �̸��� ã�� ���� ����
		sprintf(Key, "%s%d", key.c_str(), i); // key��� �̸� �ڿ� i��� ���ڰ� ���� �̸��� Key�� ����
		auto find = FindImage(Key); // Key��� �̸��� �̹����� ã�� find�� ����
		if (find == nullptr) break; // find�� nullptr�� �� �ݺ��� ����
		m_vecimg.push_back(find); // m_vecimg�� ã�� find�� �߰�
	}
	return m_vecimg; // ���� �̹������� ��� ���� m_vecimg ��ȯ
}