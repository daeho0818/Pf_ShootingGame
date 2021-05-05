#pragma once
class cTexture
{
public:
	LPDIRECT3DTEXTURE9 ptr; // LPDIRECT3DTEXTURE9 : Texture, 즉 이미지(그림)를 저장하는 구조체
	D3DXIMAGE_INFO info; // D3DXIMAGE_INFO : 이미지의 정보를 저장하는 구조체
	// cTexture() : 이미지를 만들 때 이미지와 이미지 정보를 저장
	cTexture(LPDIRECT3DTEXTURE9 ptr, D3DXIMAGE_INFO info) : ptr(ptr), info(info) {}
};