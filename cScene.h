#pragma once
class cScene abstract
{
public:
	cScene() {}
	~cScene() {}

	//virtual void func() = 0; -> ���� ���� �Լ� : ��ӵ� Ŭ�������� �������ؾ� �ϴ� �Լ�
	// Init() : �ʱ�ȭ�ϴ� �Լ� -> cTitleScene�� ������ Update() �Լ� ����
	virtual void Init() = 0;
	// Update() : ��� ����Ǵ� �Լ� -> cTitleScene�� ������ Update() �Լ� ���� (�÷��̾� �̵� �� ��ü�� ��� �ٲ�� �͵�)
	virtual void Update() = 0;
	// Render() : ��� ����Ǵ� �Լ� -> cTitleScene�� ������ Render() �Լ� ���� (�̹��� ���� �� ��ü�� �ٲ��� �ʴ� �͵�)
	virtual void Render() = 0;
	// UIRender() : ��� ����Ǵ� �Լ� -> cTitleScene�� ������ UIRender() �Լ� ���� (�̹��� ���� �� ��ü�� �ٲ��� �ʴ� �͵�)
	virtual void UIRender() = 0;
	// Release() : �����͸� �����ִ� �Լ� -> cTitleScene�� ������ Release() �Լ� ����
	virtual void Release() = 0;

	// cEndingScene.h, cTitleScene.h, cIngameScene.h �� ��ӵ�
};