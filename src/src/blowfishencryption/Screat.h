#pragma once


// Screat 

class Screat : public CDialogEx
{
	DECLARE_DYNAMIC(Screat)

public:
	Screat(CWnd* pParent = NULL);   // 
	virtual ~Screat();

	char szCurrentPath[512];//
	char szAdmin[64];   //
	char szPassWord[64];//

// 
	enum { IDD = IDD_SCRETE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditAdminame();
	afx_msg void OnEnChangeEditPassword();
};
