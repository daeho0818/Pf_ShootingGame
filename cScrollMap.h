#pragma once
class cScrollMap
{
public:
	cScrollMap();
	~cScrollMap();

	float scroll_f = 0;
	float scroll_m = 0;
	float scroll_p = 0;
	int stage = 10;

	string key;
	
	void Update(float speed);
	void Render();
};