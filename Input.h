#pragma once

//ヘッダファイルのインクルード
#include <Windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION		0x0800	
#include <dinput.h>

//入力
class Input
{
public:
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

	bool PushKey(BYTE KeyNumber);

	bool TriggerKey(BYTE KeyNumber);

public:

	void Initialize(HINSTANCE hInstance, HWND hwnd);	//初期化
	void Update();										//更新

private:
	//キーボードデバイス生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8>keyboard;

	// DirectInputの初期化
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};
};

