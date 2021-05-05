#pragma once
template<typename T> // template : ����ڰ� ���ϴ� Ÿ���� ������ �� ����
class singleton
{
public:
	static T* p; // ����ڰ� �Ѱ��� T Ÿ���� ���� p

	singleton() {}
	~singleton() {}

	// GetInstance() : �ش� Ÿ�� �� ��� �����͸� ������
	static T* GetInstance()
	{
		if (!p) // p�� ���� ���ٸ�
			p = new T; // p�� T Ÿ���� ����
		return p; // p�� ��ȯ
	}
	//ReleaseInstance() : �ش� Ÿ�� �� ��� �����͸� ������
	static void ReleaseInstance()
	{
		if (p) // p�� ���� �ִٸ�
			delete p; // p�� ����
		p = nullptr; // p�� nullptr
	}
};
template <typename T>
T* singleton<T>::p = nullptr; // ���ø� �ʱ�ȭ