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

public:

	void Initialize(HINSTANCE hInstance, HWND hwnd);	//初期化
	void Update();										//更新

private:
	//キーボードデバイス生成
	ComPtr<IDirectInputDevice8>keyboard;
};

