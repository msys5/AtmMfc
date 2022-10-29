#pragma once
#include "afxdialogex.h"
#include "structs.h"

// CWithdrawalDlg ダイアログ

class CWithdrawalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWithdrawalDlg)

private:
	Account* _account;

public:
	CWithdrawalDlg(Account* account, CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CWithdrawalDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WITHDRAWAL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CStatic _stBalance;
	CEdit _edAmount;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
