#pragma once
class cParticle
{
public:
	// 입력받은 좌표 pos와 크기 size, 종류 kind를 저장하는 생성자
	cParticle(Vec2 pos, float size, int kind, float frameTime = 0.005);
	virtual ~cParticle();

	// Update() : 계속 실행되는 함수 -> cParticleAni의 Update() 함수 실행 (대체로 바뀌는 것들)
	virtual void Update() = 0;
	// Render() : 계속 실행되는 함수 -> cParticleAni의 Render() 함수 실행 (이미지 띄우기 등 대체로 바뀌지 않는 것들)
	virtual void Render() = 0;

	Vec2 m_pos; // 입력받은 pos를 저장하는 변수, 파티클 생성 좌표
	float RenderSize; // 입력받은 size를 저장하는 변수, 파티클 크기
	bool isDestroy = false; // 파티클 제거 여부
};

