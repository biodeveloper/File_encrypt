
// blowfishencryption.cpp
//

#include "stdafx.h"
#include "blowfishencryption.h"
#include "blowfishencryptionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CblowfishencryptionApp

BEGIN_MESSAGE_MAP(CblowfishencryptionApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cblowfishencryption

CblowfishencryptionApp::CblowfishencryptionApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:
	//  InitInstance
}


//

CblowfishencryptionApp theApp;


// CblowfishencryptionApp

BOOL CblowfishencryptionApp::InitInstance()
{
	// Windows XP
	// ComCtl32.dll
	//InitCommonControlsEx
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 
	//
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// shell
	//shell
	CShellManager *pShellManager = new CShellManager;


	SetRegistryKey(_T("333333"));

	CblowfishencryptionDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 
	}

	// 
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	//
	// 
	return FALSE;
}

