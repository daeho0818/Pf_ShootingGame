#pragma once
#pragma comment(lib, "dsound.lib")

#include "SDKsound.h"
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional> //function : �Լ� �Ӹ��� �ƴ� ��� Callable('()' �� ����Ͽ� ȣ���� �� �ִ� ��� ��)�� ��ü�� ���·� ������ �� �ִ� Ŭ����
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <cstdarg> // DebugLog() �Լ� ���� ����

#define g_device DXUTGetD3D9Device() // ����̽��� �����ϴ� ���
#define Delta DXUTGetElapsedTime()// ���� �������� �Ϸ�ɶ����� �ɸ� �ð� (Unity�� Time.deltaTime)

using namespace std; // std:: �� �����ϱ� ����

using Vec2 = D3DXVECTOR2; // 2D ��ǥ ����
using Vec3 = D3DXVECTOR3; // 3D ��ǥ ����

const int WINSIZEX = 1600; // ������ ���� ũ��
const int WINSIZEY = 900; // ������ ���� ũ��

#include "cTexture.h"
#include "cScene.h"
#include "cTimer.h"
#include "cParticle.h"
#include "DebugLog.h"

#include "cImageManager.h"
#include "cSceneManager.h"
#include "cUIManager.h"
#include "cRenderManager.h"
#include "cInputManager.h"
#include "cParticleManager.h"
#include "cSoundManager.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif