#pragma once
#include "afxdialogex.h"
#include "structs.h"

// SavingDlg ダイアログ

class SavingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SavingDlg)

private:
	Account* _account;

public:
	SavingDlg(Account* account, CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~SavingDlg();

// ダイアログ データ
	enum { IDD = IDD_SAVING_DIALOG };

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
