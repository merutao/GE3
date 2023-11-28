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

	bool PushKey(BYTE KeyNumber);

	bool TriggerKey(BYTE KeyNumber);

public:

	void Initialize(HINSTANCE hInstance, HWND hwnd);	//������
	void Update();										//�X�V

private:
	//�L�[�{�[�h�f�o�C�X����
	Microsoft::WRL::ComPtr<IDirectInputDevice8>keyboard;

	// DirectInput�̏�����
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};
};

