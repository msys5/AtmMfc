#pragma once
#include "afxdialogex.h"
#include "structs.h"

// CPasswordChangeDlg ダイアログ

class CPasswordChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPasswordChangeDlg)

private:
	Account* _account;

public:
	CPasswordChangeDlg(Account* account, CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CPasswordChangeDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORD_CHANGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CEdit _edCurrentPassword;
	CEdit _edNewPassword1;
	CEdit _edNewPassword2;
public:
	virtual void OnOK();
};
