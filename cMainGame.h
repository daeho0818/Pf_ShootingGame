#pragma once
class cMainGame
{
public:
	cMainGame();
	~cMainGame();
		
	// Init() : �ʱ�ȭ�ϴ� �Լ� -> Resource() �Լ� ����, SCENE->AddScene() �Լ� ���ؼ� �� �ε�, SCENE->ChangeScene() �Լ� ���ؼ� Ÿ��Ʋ�� �ҷ�����
	void Init();
	// Update() : ��� ����Ǵ� �Լ� -> InputManager, SceneManager, ParticleManager�� Update() �Լ� ���� (��ü�� ��� �ٲ�� �͵�)
	void Update();
	// Render() : ��� ����Ǵ� �Լ� -> 
	void Render();
	// Release() : �����͸� �����ִ� �Լ� ->
	void Release();
	// LostDevice() : 
	void LostDevice();
	// ResetDevice() :
	void ResetDevice();
	// AddResource() : �������� ���Ϸκ��� �ҷ��� �ʿ� �߰��ϴ� �Լ�
	void AddResource();
};