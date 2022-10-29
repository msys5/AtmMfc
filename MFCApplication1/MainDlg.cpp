
// MFCApplication1Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include "AtmApp.h"
#include "MainDlg.h"
#include "SavingDlg.h"
#include "WithdrawalDlg.h"
#include "PasswordChangeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ダイアログ


void CMainDlg::setLoggedIn(Account* account)
{
	_loggedInAccount = account;
	_loggedIn = account != nullptr;
	_btnLogin.EnableWindow(!_loggedIn);
	_btnLogout.EnableWindow(_loggedIn);
	_btnSavings.EnableWindow(_loggedIn);
	_btnWithdrawal.EnableWindow(_loggedIn);
	_btnChangePass.EnableWindow(_loggedIn);

	if (_loggedIn) {
		CString str;
		str.Format(L"%sさんがログインしました", LPCTSTR(account->name()));
		_stMessage.SetWindowText(LPCTSTR(str));
	}
	else {
		_stMessage.SetWindowText(L"ログインしてください");
	}
}

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	_loggedIn = false;
	_loggedInAccount = nullptr;

	for (int32_t i = 0; i < AccountMax; i++)
	{
		_accounts[i] = nullptr;
	}
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, _btnSavings);
	DDX_Control(pDX, IDC_BUTTON2, _btnWithdrawal);
	DDX_Control(pDX, IDC_BUTTON3, _btnChangePass);
	DDX_Control(pDX, IDC_BUTTON4, _btnLogin);
	DDX_Control(pDX, IDC_BUTTON5, _btnLogout);
	DDX_Control(pDX, IDC_STATIC1, _stMessage);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedWithdrawal)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDlg::OnBnClickedSavings)
	ON_BN_CLICKED(IDC_BUTTON4, &CMainDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_BUTTON5, &CMainDlg::OnBnClickedLogout)
	ON_BN_CLICKED(IDC_BUTTON3, &CMainDlg::OnBnClickedChangePassword)
END_MESSAGE_MAP()


// CMFCApplication1Dlg メッセージ ハンドラー
/*
 * ダイアログが表示される前に、MFCによってこの関数が呼び出される。
 * ダイアログ内で使用するデータや画面の初期化をこの関数内で行う。
 */
BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	setLoggedIn(nullptr);
									
	// csvから口座データを読み込んでメンバに保持する
	for (int32_t i = 0; i < AccountMax; i++)
	{
		switch (i)
		{
		case 0:
			_accounts[i] = new Account(_T("田中"), _T("tanaka"), 10000);
			break;
		case 1:
			_accounts[i] = new Account(_T("鈴木"), _T("suzuki"), 20000);
			break;
		case 2:
			_accounts[i] = new Account(_T("佐藤"), _T("satou"),  30000);
			break;
		}
	}


	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMainDlg::OnBnClickedLogin()
{
	setLoggedIn(_accounts[0]);
}


void CMainDlg::OnBnClickedLogout()
{
	setLoggedIn(nullptr);
}


void CMainDlg::OnBnClickedWithdrawal()
{
	CWithdrawalDlg dlg(_loggedInAccount, this);
	dlg.DoModal();
}


void CMainDlg::OnBnClickedSavings()
{
	SavingDlg dlg(_loggedInAccount, this);
	dlg.DoModal();
}

void CMainDlg::OnBnClickedChangePassword()
{
	CPasswordChangeDlg dlg(_loggedInAccount, this);
	dlg.DoModal();
}
