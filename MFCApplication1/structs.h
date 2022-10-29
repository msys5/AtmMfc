#pragma once

#include <stdint.h>

// ATM����
enum class AtmCommand {
	Withdrawal,		// �����o��
	Savings,		// �a������
	ChangePassword,	// �p�X���[�h�ύX
};

// �������
class Account {
private:
	CString _name;		// ���`�l
	CString _password;	// �p�X���[�h
	int32_t _balance;	// �c��

public:
#pragma region constructors
	Account(const CString& name, const CString& password, int32_t balance)
		: _name(name), _password(password), _balance(balance) {
		
	}
#pragma endregion

#pragma region getters
	/*
	 * �@�O������̕s�p�ӂȒl�̐ݒ��h�����߂Ƀ����o�ϐ���private�ɂ���
	 * �@getter������public�ɂ��Ă���
	 * 
	 * �Agetter�̓����o�ϐ���Ԃ��P���Ȋ֐��̈׃w�b�_�[�t�@�C���ɒ��ڋL�ڂ��Ă����͖��Ȃ�
	 * 
	 * �Bstd::string�Ȃǂ̃T�C�Y���傫���f�[�^�͎Q�Ƃ܂��̓|�C���^��Ԃ��悤�ɂ���Ƃ悢 (�Ȃ�ׂ��Q��)
	 * �@int�Ȃǂ̃T�C�Y����r�I������(16�o�C�g�ȉ���ڈ�)�f�[�^�Ȃ�l�n���ł悢
	 */

	CString& name() { return _name; }
	CString& password() { return _password; }
	int32_t balance() { return _balance; }
#pragma endregion

#pragma region operation
	/*
	 * �@�����ɑ΂��鑀��Ƃ��� "�a������" "�����o��" "�p�X���[�h�ύX" ������
	 * �@�������������Ă���
	 * 
	 * �A������cpp�t�@�C���ɋL�ڂ��Ă����Ƃ悢
	 */

	// �a������
	void savings(int32_t amount);

	// �����o��
	void withdrawal(int32_t amount);

	// �p�X���[�h�ύX
	void changePassword(const CString& newPass);

#pragma endregion

};