//�w�b�_�t�@�C���̃C���N���[�h
#include "Input.h"
#include <dinput.h>
#include <wrl.h>
#include <cassert>

#define DIRECTINPUT_VERSION		0x0800	

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

using namespace Microsoft::WRL;

//������
void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	//DirectInput
	ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//�L�[�{�[�h�f�o�C�X����
	ComPtr<IDirectInputDevice8>keyboard;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//���̓f�[�^�`���̃Z�b�g
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	//�r�����䃌�x���̃Z�b�g
	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

//�X�V
void Input::Update()
{

}
