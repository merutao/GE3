//ヘッダファイルのインクルード
#include "Input.h"
#include <cassert>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

//using namespace Microsoft::WRL;

//初期化
void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	//DirectInput
	ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//キーボードデバイス生成
	/*ComPtr<IDirectInputDevice8>keyboard;*/
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

//更新
void Input::Update()
{
	// キーボード情報の取得開始
	keyboard->Acquire();
	// 全キーの入力状態を取得する
	BYTE key[256] = {};
	keyboard->GetDeviceState(sizeof(key), key);
}

