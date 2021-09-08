#pragma once
class cButton
{
public:
	cButton(cTexture* img, Vec2 pos, float size, function<void()> func) : m_img(img), m_pos(pos), m_size(size), m_func(func)
	{
		m_rect.left = pos.x - img->info.Width / 2 * size;
		m_rect.top = pos.y - img->info.Height / 2 * size;
		m_rect.right = pos.x + img->info.Width / 2 * size;
		m_rect.bottom = pos.y + img->info.Height / 2 * size;
	}
	~cButton();

	void InitImgs(cTexture* basicImg, cTexture* overImg, cTexture* pressedImg);
	void SetImg(int index);
	void SetImg(cTexture* img);

	cTexture* GetImg(int index);
	Vec2 GetPos();
	float GetSize();
	function<void()> GetFunc();
	bool ChkCollision(Vec2 position);

	cTexture* m_img = nullptr;
	bool lButtonDown = false;
	bool lButtonUp = false;

private:
	cTexture* m_basicImg = nullptr;
	cTexture* m_overImg = nullptr;
	cTexture* m_pressedImg = nullptr;
	Vec2 m_pos;
	RECT m_rect;
	float m_size;
	function<void()> m_func;
};

