#pragma once
class cTexture
{
public:
	LPDIRECT3DTEXTURE9 ptr; // LPDIRECT3DTEXTURE9 : Texture, �� �̹���(�׸�)�� �����ϴ� ����ü
	D3DXIMAGE_INFO info; // D3DXIMAGE_INFO : �̹����� ������ �����ϴ� ����ü
	// cTexture() : �̹����� ���� �� �̹����� �̹��� ������ ����
	cTexture(LPDIRECT3DTEXTURE9 ptr, D3DXIMAGE_INFO info) : ptr(ptr), info(info) {}
};