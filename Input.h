#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include <Windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION		0x0800	
#include <dinput.h>

//����
class Input
{
public:
	//namespace�ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:

	void Initialize(HINSTANCE hInstance, HWND hwnd);	//������
	void Update();										//�X�V

private:
	//�L�[�{�[�h�f�o�C�X����
	ComPtr<IDirectInputDevice8>keyboard;
};

