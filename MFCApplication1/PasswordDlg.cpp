// CPasswordDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include "AtmApp.h"
#include "PasswordDlg.h"


// CPasswordDlg ダイアログ

IMPLEMENT_DYNAMIC(CPasswordDlg, CDialogEx)

CPasswordDlg::CPasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PASSWORD_DIALOG, pParent)
{

}

CPasswordDlg::~CPasswordDlg()
{
}

bool CPasswordDlg::matchPassword(Account* account)
{
	if (DoModal() != IDOK) {
		return false;
	}

	if (_passwordMemory == account->password()) {
		return true;
	}

	MessageBox(_T("パスワードが違います"), _T("Error"));
	return false;
}

void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _edPassword);
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPasswordDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPasswordDlg メッセージ ハンドラー


BOOL CPasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void CPasswordDlg::OnBnClickedOk()
{
	_edPassword.GetWindowText(_passwordMemory);

	CDialogEx::OnOK();
}
