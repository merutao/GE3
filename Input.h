#pragma once

//ヘッダファイルのインクルード
#include <Windows.h>

//入力
class Input
{
public:

	void Initialize(HINSTANCE hInstance, HWND hwnd);	//初期化
	void Update();										//更新
};

