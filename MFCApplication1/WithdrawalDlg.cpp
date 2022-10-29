// WithdrawalDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "afxdialogex.h"
#include "AtmApp.h"
#include "WithdrawalDlg.h"
#include "PasswordDlg.h"

// CWithdrawalDlg ダイアログ

IMPLEMENT_DYNAMIC(CWithdrawalDlg, CDialogEx)

CWithdrawalDlg::CWithdrawalDlg(Account* account, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WITHDRAWAL_DIALOG, pParent),
	_account(account)
{

}

CWithdrawalDlg::~CWithdrawalDlg()
{
}

void CWithdrawalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, _stBalance);
	DDX_Control(pDX, IDC_EDIT1, _edAmount);
}


BEGIN_MESSAGE_MAP(CWithdrawalDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWithdrawalDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWithdrawalDlg メッセージ ハンドラー


BOOL CWithdrawalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;

	// 残高表示
	str.Format(_T("%d"), _account->balance());
	_stBalance.SetWindowText(LPCTSTR(str));

	// 引き出し金額表示
	_edAmount.SetWindowText(_T("0"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void CWithdrawalDlg::OnBnClickedOk()
{
	CString str;
	_edAmount.GetWindowText(str);
	int32_t amount = _ttoi(str);

	if (amount > 0 && _account->balance() - amount >= 0) {
		CPasswordDlg dlg(this);
		if (dlg.matchPassword(_account)) {
			_account->withdrawal(amount);

			str.Format(_T("引き出しが完了しました。残高は %d円 です。"), _account->balance());
			MessageBox(str, _T("Message"));

			CDialogEx::OnOK();
		}
	}
	else {
		MessageBox(_T("無効な数値が入力されました"), _T("Error"));
	}
}
