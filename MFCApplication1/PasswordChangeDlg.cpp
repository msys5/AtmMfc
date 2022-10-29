// PasswordChangeDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "afxdialogex.h"
#include "PasswordChangeDlg.h"
#include "AtmApp.h"

// CPasswordChangeDlg ダイアログ

IMPLEMENT_DYNAMIC(CPasswordChangeDlg, CDialogEx)

CPasswordChangeDlg::CPasswordChangeDlg(Account* account, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PASSWORD_CHANGE_DIALOG, pParent),
	_account(account)
{

}

CPasswordChangeDlg::~CPasswordChangeDlg()
{
}

void CPasswordChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _edCurrentPassword);
	DDX_Control(pDX, IDC_EDIT2, _edNewPassword1);
	DDX_Control(pDX, IDC_EDIT3, _edNewPassword2);
}


BEGIN_MESSAGE_MAP(CPasswordChangeDlg, CDialogEx)
END_MESSAGE_MAP()


// CPasswordChangeDlg メッセージ ハンドラー


void CPasswordChangeDlg::OnOK()
{
	CString currentPass;
	CString newPass1;
	CString newPass2;

	_edCurrentPassword.GetWindowText(currentPass);
	_edNewPassword1.GetWindowText(newPass1);
	_edNewPassword2.GetWindowText(newPass2);

	if (currentPass.GetLength() == 0) {
		MessageBox(_T("現在のパスワードを入力してください"), _T("Error"));
		return;
	}

	if (newPass1.GetLength() == 0) {
		MessageBox(_T("新しいパスワードを入力してください"), _T("Error"));
		return;
	}

	if (newPass1 != newPass2)
	{
		MessageBox(_T("新しいパスワードと確認用パスワードが一致しません"), _T("Error"));
		return;
	}

	_account->changePassword(newPass1);
	MessageBox(_T("パスワードを変更しました"), _T("Message"));

	CDialogEx::OnOK();
}
