#pragma once

#include <stdint.h>

// ATM操作
enum class AtmCommand {
	Withdrawal,		// 引き出し
	Savings,		// 預け入れ
	ChangePassword,	// パスワード変更
};

// 口座情報
class Account {
private:
	CString _name;		// 名義人
	CString _password;	// パスワード
	int32_t _balance;	// 残高

public:
#pragma region constructors
	Account(const CString& name, const CString& password, int32_t balance)
		: _name(name), _password(password), _balance(balance) {
		
	}
#pragma endregion

#pragma region getters
	/*
	 * ①外部からの不用意な値の設定を防ぐためにメンバ変数はprivateにして
	 * 　getterだけをpublicにしている
	 * 
	 * ②getterはメンバ変数を返す単純な関数の為ヘッダーファイルに直接記載しても大抵は問題ない
	 * 
	 * ③std::stringなどのサイズが大きいデータは参照またはポインタを返すようにするとよい (なるべく参照)
	 * 　intなどのサイズが比較的小さい(16バイト以下を目安)データなら値渡しでよい
	 */

	CString& name() { return _name; }
	CString& password() { return _password; }
	int32_t balance() { return _balance; }
#pragma endregion

#pragma region operation
	/*
	 * ①口座に対する操作として "預け入れ" "引き出し" "パスワード変更" がある
	 * 　これらを実装していく
	 * 
	 * ②実装はcppファイルに記載していくとよい
	 */

	// 預け入れ
	void savings(int32_t amount);

	// 引き出し
	void withdrawal(int32_t amount);

	// パスワード変更
	void changePassword(const CString& newPass);

#pragma endregion

};