#pragma once
#include "afxdialogex.h"
#include "structs.h"

// CPasswordDlg ダイアログ

class CPasswordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPasswordDlg)

public:
	CPasswordDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CPasswordDlg();

	bool matchPassword(Account* account);

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CString _passwordMemory;
	CEdit _edPassword;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
