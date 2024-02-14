#include "Input.h"
#include <assert.h>
using namespace Microsoft::WRL;

void Input::Initialize(WinApp* winApp)
{

	winApp_ = winApp;

	HRESULT result;

	result = DirectInput8Create(
		winApp->GetHinstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));


	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	// ���̓f�[�^�`���̃Z�b�g
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
	assert(SUCCEEDED(result));
	// �r�����䃌�x���̃Z�b�g
	result = keyboard->SetCooperativeLevel(
		winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update()
{
	//keyPre�̒���key����ۑ�
	memcpy(keyPre, key, sizeof(key));

	// �L�[�{�[�h���̎擾�J�n
	keyboard->Acquire();
	// �S�L�[�̓��͏�Ԃ��擾����
	keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber) {
	//�C�ӂ̃{�^����������Ă��邩
	if (key[keyNumber]) {
		return true;
	}
	//�C�ӂ̃{�^����������Ă��Ȃ������Ƃ�
	return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{

	if (key[keyNumber] && keyPre[keyNumber] == 0) {
		return true;
	}
	return false;
}