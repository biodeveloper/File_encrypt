
// blowfishencryptionDlg.h : 
//
//#include "resource.h¡°
#include "stdafx.h"
#include "afxdialogex.h"
#include"string.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++²
#include "EncryptionInterface.h"
#include"MD5.h"
#include"Folderoperate.h"

#pragma once


// CblowfishencryptionDlg ¶Ô»°¿ò
class CblowfishencryptionDlg : public CDialogEx
{
// 
public:
	CblowfishencryptionDlg(CWnd* pParent = NULL);	// 

// 
	enum { IDD = IDD_BLOWFISHENCRYPTION_DIALOG };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// 


// 
protected:
	HICON m_hIcon;

	// 
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnchosesrcfile();
	afx_msg void OnBnClickedBtnenorden();

	//CIPHER _cipher;
	char _readFile[MAX_PATH];
	char _writeFile[MAX_PATH];
    char _password[100];
	char _password1[100];
	char md5hash[MAX_PATH];
	CString hashresult;
	CString hashresult1;
   // BlowFishEnc encryption;
	MD5 iMD5;
	Folderoperate folderoperate;
	CString readmima;
	CString readmima1;
	CString m_editmima;
	CString m_editmima1;
	afx_msg void OnBnClickedBtnchoosedestfile();
	void wipePwds(char *pwd, char *verify);
	afx_msg void OnBnClickedBtnsuaxin();
	afx_msg void OnBnClickedRadiojimi();
	afx_msg void OnBnClickedRadiojiemi();
	afx_msg void OnBnClickedRadioblowfish();
	afx_msg void OnBnClickedRadio3des();
	afx_msg void OnBnClickedLoginbutton();
	afx_msg void OnBnClickedButtonLogout();
	afx_msg void OnBnClickedButtonChange();

//
public:
	//afx_msg void OnBnClickedLoginbutton();
	// 
	CButton m_LonginButton;
	// 
	CButton m_logoutButton;
	// 
	CStatic m_static_adminName;

	//afx_msg void OnBnClickedButtonLogout();

	// 
	CButton m_changeButton;
	//afx_msg void OnBnClickedButtonChange();

	afx_msg void OnStnClickedadminname();

	afx_msg void OnBnClickedTwice();

	afx_msg void OnBnClickedButtonKeys();
	afx_msg void OnBnClickedButtonOpenfile();

	CString m_editquerenmima;
	afx_msg void OnBnClickedButtonLog();

	CButton m_generatekeyButton;
	CButton m_openfileButton;

	//
	CString	FilePath;
	int typetotal;
	// 
	void FindFiles(CString sPath);
	CStringArray typeArray;
	struct typeCount{
		CString type;
		int num;
	}TypeCount[1000];
	afx_msg void OnBnClickedButtonDriver();
};
