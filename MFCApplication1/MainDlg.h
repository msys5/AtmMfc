
// MFCApplication1Dlg.h : ヘッダー ファイル
//

#pragma once
#include <stdint.h>
#include "structs.h"

// CMFCApplication1Dlg ダイアログ
class CMainDlg : public CDialogEx
{
private:
	static const int32_t AccountMax = 10;

	Account* _accounts[AccountMax];		// 通常はstd::vectorなどを使うことが推奨されるが今回はあえてポインタの配列を使用する
										// インスタンスの配列ではなくポインタの配列を使うのは意図的で、
										// 最大アカウントは10だが3アカウントしか使用しない場合に残りの要素をnullptrとして扱うため。
	bool _loggedIn;
	Account* _loggedInAccount;
	void setLoggedIn(Account* account);

// コンストラクション
public:
	CMainDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CButton _btnSavings;
	CButton _btnLogin;
	CButton _btnLogout;
	CButton _btnWithdrawal;
	CButton _btnChangePass;
	CStatic _stMessage;
public:
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedLogout();
	afx_msg void OnBnClickedSavings();
	afx_msg void OnBnClickedWithdrawal();
	afx_msg void OnBnClickedChangePassword();
};
