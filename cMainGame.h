#pragma once
class cMainGame
{
public:
	cMainGame();
	~cMainGame();
		
	// Init() : 초기화하는 함수 -> Resource() 함수 실행, SCENE->AddScene() 함수 통해서 씬 로드, SCENE->ChangeScene() 함수 통해서 타이틀씬 불러오기
	void Init();
	// Update() : 계속 실행되는 함수 -> InputManager, SceneManager, ParticleManager의 Update() 함수 실행 (대체로 계속 바뀌는 것들)
	void Update();
	// Render() : 계속 실행되는 함수 -> 
	void Render();
	// Release() : 데이터를 지워주는 함수 ->
	void Release();
	// LostDevice() : 
	void LostDevice();
	// ResetDevice() :
	void ResetDevice();
	// AddResource() : 사진들을 파일로부터 불러와 맵에 추가하는 함수
	void AddResource();
};