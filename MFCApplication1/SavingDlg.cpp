// SavingDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include "AtmApp.h"
#include "SavingDlg.h"
#include "PasswordDlg.h"

// SavingDlg ダイアログ

IMPLEMENT_DYNAMIC(SavingDlg, CDialogEx)

SavingDlg::SavingDlg(Account* account, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAVING_DIALOG, pParent),
	_account(account)
{

}

SavingDlg::~SavingDlg()
{
}

void SavingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, _stBalance);
	DDX_Control(pDX, IDC_EDIT1, _edAmount);
}


BEGIN_MESSAGE_MAP(SavingDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SavingDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SavingDlg メッセージ ハンドラー


BOOL SavingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;

	// 残高表示
	str.Format(_T("%d"), _account->balance());
	_stBalance.SetWindowText(LPCTSTR(str));

	// 預け入れ金額表示
	_edAmount.SetWindowText(_T("0"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void SavingDlg::OnBnClickedOk()
{
	CString str;
	_edAmount.GetWindowText(str);
	int32_t amount = _ttoi(str);

	if (amount > 0) {
		CPasswordDlg dlg(this);
		if (dlg.matchPassword(_account)) {
			_account->savings(amount);

			str.Format(_T("預け入れが完了しました。残高は %d円 です。"), _account->balance());
			MessageBox(str, _T("Message"));

			CDialogEx::OnOK();
		}
	}
	else {
		MessageBox(_T("無効な数値が入力されました"), _T("Error"));
	}
}
