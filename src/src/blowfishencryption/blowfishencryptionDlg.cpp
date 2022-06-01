
// blowfishencryptionDlg.cpp :
//
#include"resource.h"
#include "stdafx.h"
#include "blowfishencryption.h"
#include "blowfishencryptionDlg.h"
#include "afxdialogex.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++
#include "EncryptionInterface.h"
#include "run.h"
#include "MD5.h"
#include"Folderoperate.h"

#include "stdafx.h"
#include "afxdialogex.h"
#include "Screat.h"
#include "Change.h"

#include "Random.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#ifndef EncryptionInterface.h
//#define EncryptionInterface.h
//#endif


//

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

//
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 

// 
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CblowfishencryptionDlg




CblowfishencryptionDlg::CblowfishencryptionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CblowfishencryptionDlg::IDD, pParent)
	, m_editquerenmima(_T(""))
{   //BlowFishEnc encryption;
	//BlowFishEnc encryption(const char *pwd);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//m_mima = _T("");
	m_editmima = _T("");
	m_editmima1 = _T("");
}

void CblowfishencryptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_mima, m_mima);
	DDX_Text(pDX, IDC_EDITmima, m_editmima);
	DDX_Text(pDX, IDC_EDITquerenmima, m_editmima1);
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LoginButton, m_LonginButton);
	DDX_Control(pDX, IDC_BUTTON_LOGOUT, m_logoutButton);
	DDX_Control(pDX, IDC_adminName, m_static_adminName);

	DDX_Control(pDX, IDC_BUTTON_CHANGE, m_changeButton);



	DDX_Control(pDX, IDC_BUTTON_KEYS, m_generatekeyButton);
	DDX_Control(pDX, IDC_BUTTON_OPENFILE, m_openfileButton);
}

BEGIN_MESSAGE_MAP(CblowfishencryptionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btnchosesrcfile, &CblowfishencryptionDlg::OnBnClickedBtnchosesrcfile)
	ON_BN_CLICKED(IDC_Btnenorden, &CblowfishencryptionDlg::OnBnClickedBtnenorden)
	ON_BN_CLICKED(IDC_Btnchoosedestfile, &CblowfishencryptionDlg::OnBnClickedBtnchoosedestfile)
	ON_BN_CLICKED(IDC_Btnsuaxin, &CblowfishencryptionDlg::OnBnClickedBtnsuaxin)
	ON_BN_CLICKED(IDC_RADIOjimi, &CblowfishencryptionDlg::OnBnClickedRadiojimi)
	ON_BN_CLICKED(IDC_RADIOjiemi, &CblowfishencryptionDlg::OnBnClickedRadiojiemi)
	ON_BN_CLICKED(IDC_RADIOblowfish, &CblowfishencryptionDlg::OnBnClickedRadioblowfish)
	ON_BN_CLICKED(IDC_RADIO3des, &CblowfishencryptionDlg::OnBnClickedRadio3des)
	ON_BN_CLICKED(IDC_LoginButton, &CblowfishencryptionDlg::OnBnClickedLoginbutton)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CblowfishencryptionDlg::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CblowfishencryptionDlg::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_TWICE, &CblowfishencryptionDlg::OnBnClickedTwice)
	ON_BN_CLICKED(IDC_BUTTON_KEYS, &CblowfishencryptionDlg::OnBnClickedButtonKeys)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CblowfishencryptionDlg::OnBnClickedButtonOpenfile)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CblowfishencryptionDlg::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_DRIVER, &CblowfishencryptionDlg::OnBnClickedButtonDriver)
END_MESSAGE_MAP()


// CblowfishencryptionDlg

BOOL CblowfishencryptionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 

	// IDM_ABOUTBOX
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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


	SetIcon(m_hIcon, TRUE);			// 
	SetIcon(m_hIcon, FALSE);		//

	// TODO
	

	return TRUE;  // 
}

void CblowfishencryptionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CblowfishencryptionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		//
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//
//
HCURSOR CblowfishencryptionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//
void CblowfishencryptionDlg::OnBnClickedBtnchosesrcfile()
{
	// TODO: Add your control notification handler code here
     char resultFile[MAX_PATH];
	 char destfile[MAX_PATH];
	  if((IsDlgButtonChecked(IDC_RADIOblowfish) != BST_CHECKED)&&(IsDlgButtonChecked(IDC_RADIO3des)!= BST_CHECKED)&&(IsDlgButtonChecked(IDC_TWICE)!= BST_CHECKED))
	  MessageBox("请选择解密算法");
	  else
	  {
		  if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//
		  {  
			  if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//
			  {
				  CFileDialog filedlg(true);//
				  filedlg.m_ofn.lpstrTitle=(_T("选择加密文件"));//
				  filedlg.m_ofn.lpstrFilter=_T("All Files(*.*)\0*.*\0\0");//
				  if(IDOK==filedlg.DoModal())
				  {
					  SetDlgItemText(IDC_srcfile,filedlg.GetPathName());//
					  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
					  
						  if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
						  strcat(resultFile,".enc");
					      if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
                          strcat(resultFile,".encD");
						  else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
						  {
								strcat(resultFile,".encD.enc");
						  }
						  SetDlgItemText(IDC_destfile,resultFile);
					 // }
				  }
				  return;
			  }
			  if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
			  {

				  SetDlgItemText(IDC_srcfile,folderoperate.openFloder());
				  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 // GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
				 // if(strlen(destfile)==0)
				  //{
					  //strcat(resultFile,".encD.enc");//
					  SetDlgItemText(IDC_destfile,resultFile);
				  //}
				  return;
			  }
		  }
		  else if(IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//
		  {  
			  if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//
			  {
				  CFileDialog filedlg(FALSE);//
				  filedlg.m_ofn.lpstrTitle=(_T("保存解密文件"));//
				  filedlg.m_ofn.lpstrFilter=_T("All Files(*.*)\0*.*\0\0");//
				  if(IDOK==filedlg.DoModal())
				  {  
					  SetDlgItemText(IDC_srcfile,filedlg.GetPathName());
					  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);//
					  GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
					 
					  if(strlen(destfile)>4)
					  {
						  destfile[strlen(destfile)-4]=0;
						  if(resultFile!=destfile)
							  MessageBox("确定要重写源文件文件吗？");
					  }
				  }
				  return;
			  }
			  if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
			  {

				  SetDlgItemText(IDC_destfile,folderoperate.openFloder());
				  GetDlgItemText(IDC_destfile,resultFile,MAX_PATH);
				  GetDlgItemText(IDC_srcfile,destfile,MAX_PATH);
				  if(strlen(destfile)==0)
				  {
					  //strcat(resultFile,".encD.enc");
					  SetDlgItemText(IDC_srcfile,resultFile);
				  }
				  return;
			  }
		  }

	  }

	return ;
}


//加解密
void CblowfishencryptionDlg::OnBnClickedBtnenorden()
{
	// TODO: Add your control notification handler code here
	//获得明文路径，密文路径和密码
	char source[MAX_PATH];
	GetDlgItemText(IDC_srcfile, source, MAX_PATH);
	char dest[MAX_PATH];
	GetDlgItemText(IDC_destfile, dest, MAX_PATH);

	char tempfile[MAX_PATH];
	GetDlgItemText(IDC_srcfile, tempfile, MAX_PATH);
	if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED && IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)
	{
		strcat(tempfile,".encD");//如果不进行判断，则会出现文件夹加密中后缀错误
	}
	/*
	if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED  && IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)
	{
		strcat(tempfile,".encD.enc");
	}
	*/
	char password[57];//
	GetDlgItemText(IDC_EDITmima, password, 56);
	password[56]=0;
    char passverify[57];//
	GetDlgItemText(IDC_EDITquerenmima, passverify, 56);
	passverify[56] = 0;

	//
    strncpy(_password, password, 100);
	strncpy(_password1, passverify, 100);
	bool mark=true;//true琭alse
    run runing;//
	if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//
	{
		if (!PathFileExists(source))
		{
			MessageBox("加密文件不存在.", "错误");
			wipePwds(password, passverify);
			return ;
		}

		strcpy(_readFile,source );
		strcpy(_writeFile, dest);
		const char*hashresultvalue;
		if(IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//
		{
			//
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			//{
		
			//MD5 iMD5;
			hashresult=iMD5.md5file(_readFile);
			hashresultvalue=(LPCTSTR)hashresult;
			//}
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
				runing.processing(mark,_readFile,_writeFile,password);//
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
				runing.desprocess(mark,_readFile,_writeFile,password,passverify);//
			if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{					
				runing.desprocess(mark,_readFile,tempfile,password,passverify);//			
				runing.processing(mark,tempfile,_writeFile,password);//
				runing.clearing(tempfile);
			}

			AfxMessageBox("加密完成");
			runing.clearing(_readFile);//		
			//
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			//{

			//MD5 iMD5;
			iMD5.writehashtofile(_writeFile,hashresultvalue);
			//}
			//
            runing.writemimatofile(_writeFile,password);//
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//
			{
			   char *str=";";
	           runing.writemimatofile(_writeFile,str);//
			   runing.writemimatofile(_writeFile,passverify);//
			}
            wipePwds(password, passverify);
			return;
		}

		if(IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
		{
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
				folderoperate.EncDencFolder(mark,source,dest,password);//
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
				folderoperate.EncDencDESFolder(mark,source,dest,password,passverify);//
			if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				folderoperate.EncDencDESFolder(mark,source,tempfile,password,passverify);
				folderoperate.EncDencFolder(mark,tempfile,dest,password);
				//runing.clearing(tempfile);//
			}
			AfxMessageBox("加密完成");
			wipePwds(password, passverify);
			return;
		}
	}
	else if (IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//
	{
		if (!PathFileExists(dest))
		{
			MessageBox("要解密文件不存在.", "错误");
			wipePwds(password, passverify);
			return ;
		}
		mark=false;//
		strcpy(_readFile, dest);
		strcpy(_writeFile, source);
		//hash
		 CString readhash;
       if(IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//
	    {
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)//
			//{
			if((IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED) ||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//
			{
				readmima1=runing.readmimafromfile(_readFile);//
				readmima=runing.readmima1fromfile(_readFile,readmima1.GetLength());//
			// runing.rebackencfile(_readFile,readmima1.GetLength()+1);//
			}
			else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				readmima=runing.readmimafromfile(_readFile);//
			}
			//
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//
			{
               if((readmima!=password)&&(readmima1!=passverify))
			   { 
				   AfxMessageBox("输入密码错误，请重新输入密码");
			       return;
			   }
              runing.rebackencfile(_readFile,readmima.GetLength()+readmima1.GetLength()+2);//
			}
			else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				if(readmima!=password)//
				{
					{
						AfxMessageBox("---");
						return;
					}
				}
				runing.rebackencfile(_readFile,readmima.GetLength()+1);//
			}
			readhash=iMD5.readhashfromfile(_readFile);//
			runing.rebackencfile(_readFile,32);//
			// }
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				runing.processing(mark,_readFile,_writeFile,password);//
				hashresult1=iMD5.md5file(_writeFile);
			}
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			{
				runing.desprocess(mark,_readFile,_writeFile,password,passverify);//
				hashresult1=iMD5.md5file(_writeFile);
			}
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				runing.processing(mark,_readFile,tempfile,password);//blowfish
				runing.desprocess(mark,tempfile,_writeFile,password,passverify);//
				runing.clearing(tempfile);//
				hashresult1=iMD5.md5file(_writeFile);
			}
			//runing.processing(mark,_readFile,_writeFile,password);//
			AfxMessageBox("解密完成");
			runing.clearing(_readFile);//
			wipePwds(password, passverify);

			
			// if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			// {
			// MD5 iMD5;
			//hashresult1=iMD5.md5file(_writeFile);

			
			if(hashresult1==readhash)
			{
				MessageBox("888888");
			}
			else if(hashresult1!=readhash)
			{
				MessageBox("9999999999");
			}
			
             return;
		 }
		  
	   
	   if(IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
	   {   
		   int mimamark;
		   if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			    mimamark= folderoperate.EncDencFolder(mark,source,dest,password);//
		   if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			    mimamark=folderoperate.EncDencDESFolder(mark,source,dest,password,passverify);//
		   if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
		   {
			    mimamark= folderoperate.EncDencFolder(mark,tempfile,dest,password);
				mimamark=folderoperate.EncDencDESFolder(mark,source,tempfile,password,passverify);
		   }
		  if(mimamark==1)
		  return;
		  AfxMessageBox("ggg");
		  wipePwds(password, passverify);
          return ;
		}		
	}	
	else
	{
		MessageBox("ddd", "磄g");
	}
	//wipePwds(password, passverify);
	return ;	
}

//密文路径选择
void CblowfishencryptionDlg::OnBnClickedBtnchoosedestfile()
{
	// TODO: Add your control notification handler code here
	char resultFile[MAX_PATH]; 
	char destfile[MAX_PATH];
	//CFileDialog filedlg(mark);//
	if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//
	{  
		if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//如果为单一文件
		{
			CFileDialog filedlg(FALSE);//
			filedlg.m_ofn.lpstrTitle=(_T("保存解密文件"));//
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//
			}
            else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.encD)\0*.encD\0\0");//
			}
			/*
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc.encD)\0*.enc.encD\0\0");
			}
			*/

			if(IDOK==filedlg.DoModal())
			{  
				SetDlgItemText(IDC_destfile,filedlg.GetPathName());
				GetDlgItemText(IDC_destfile,destfile,MAX_PATH);//
				GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				if(strlen(resultFile)!=0)
				{
					strcat(resultFile,".enc");
					if(resultFile!=destfile)
						MessageBox("确定要重写加密文件吗？");
				}
			}
			return;
		}
		if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
		  {
            
			 SetDlgItemText(IDC_destfile,folderoperate.openFloder());
			 GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
			 GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 if(strlen(resultFile)==0)
				 {
					 //strcat(resultFile,".enc");
					 SetDlgItemText(IDC_srcfile,destfile);
				 }
			 return;
		  }

	} 
	else if(IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//
	{
		if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//
		{
			CFileDialog filedlg(true);//
			filedlg.m_ofn.lpstrTitle=(_T("选择解密文件"));//
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
            filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//		  
            else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
            filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.encD)\0*.encD\0\0");//               
			/*
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc.encD)\0*.encD\0\0");
			*/	
			//filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//
			if(IDOK==filedlg.DoModal())
			{

				SetDlgItemText(IDC_destfile,filedlg.GetPathName());//
				GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
				if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)//
					destfile[strlen(destfile)-9]=0;
				else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)//
					destfile[strlen(destfile)-4]=0;
				else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)//
				{
					destfile[strlen(destfile)-5]=0;
					strcpy(resultFile,destfile);
					SetDlgItemText(IDC_srcfile,resultFile);
				}
			}
			return;
		}
		if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//
		  {
            
			 SetDlgItemText(IDC_destfile,folderoperate.openFloder());
			 GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
			// GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 //if(strlen(resultFile)==0)
				 //{
					 //strcat(resultFile,".enc");
					 SetDlgItemText(IDC_srcfile,destfile);
				// }
			 return;
		  }
	}

	
	return ;


}

//
void CblowfishencryptionDlg::wipePwds(char *pwd, char *verify)
{
	if (pwd != 0)		ZeroMemory(pwd, 57);
	if (verify != 0)	ZeroMemory(verify, 57);
}

//界面更新
void CblowfishencryptionDlg::OnBnClickedBtnsuaxin()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_EDITmima,0);
	SetDlgItemText(IDC_EDITquerenmima,0);
	SetDlgItemText(IDC_srcfile,0);
	SetDlgItemText(IDC_destfile,0);

}

//
void CblowfishencryptionDlg::OnBnClickedRadiojimi()
{
	// TODO: Add your control notification handler code here
   GetDlgItem(IDC_Btnchosesrcfile)->EnableWindow(true);//
   GetDlgItem(IDC_Btnchoosedestfile)->EnableWindow(false);//

}

//
void CblowfishencryptionDlg::OnBnClickedRadiojiemi()
{
	// TODO: Add your control notification handler code here
	 GetDlgItem(IDC_Btnchosesrcfile)->EnableWindow(false);//
	 GetDlgItem(IDC_Btnchoosedestfile)->EnableWindow(true);//
}

//blowfish
void CblowfishencryptionDlg::OnBnClickedRadioblowfish()
{
	// TODO: Add your control notification handler code here
	 GetDlgItem(IDC_EDITquerenmima)->EnableWindow(false);//

}


//
void CblowfishencryptionDlg::OnBnClickedRadio3des()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDITquerenmima)->EnableWindow(true);//
}


void CblowfishencryptionDlg::OnBnClickedLoginbutton()
{
	// TODO: 
	Screat dlg;
	dlg.DoModal();
}


void CblowfishencryptionDlg::OnBnClickedButtonLogout()
{
	// TODO: 
	m_LonginButton.ShowWindow(SW_SHOW);
	
	m_logoutButton.ShowWindow(SW_HIDE);
	m_changeButton.ShowWindow(SW_HIDE);
	m_static_adminName.ShowWindow(SW_HIDE);
}


void CblowfishencryptionDlg::OnBnClickedButtonChange()
{
	// TODO:
	Change dlg;
	dlg.DoModal();
}


void CblowfishencryptionDlg::OnBnClickedTwice()
{
	// TODO:
}


void CblowfishencryptionDlg::OnBnClickedButtonKeys()
{
	// TODO:
	UpdateData(TRUE);

	//
	if( m_editmima == "")
	{
		CString szKey2;
		srand(time(NULL));
		char name[LEN_NAME + 2];
		CRandom random;
		szKey2 = random.rand_str(name,LEN_NAME);
		if (IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED || IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
		{
			m_editmima = szKey2;
			m_editmima1 = szKey2;
		} else {
			m_editmima = szKey2;
		}
	}

	if(m_editmima1 == "")
	{
		m_editmima1 = m_editmima;
	}

	UpdateData(FALSE);

	//
	//
	UpdateData(TRUE);
	
	  

	UpdateData(FALSE);

	CTime time; 
	time =CTime::GetCurrentTime();//
	CString timeStr = time.Format("\r\n %Y-%m-%d %H:%M:%S ");

	//
	CString str = _T("【密码】：");
	str =  timeStr + str ;
	str += m_editmima;

	CFile file( KEYFILE_NAME, CFile::modeNoTruncate| CFile::modeWrite);
	file.SeekToEnd();
	file.Write(str,strlen(str));
	file.Close();
}


void CblowfishencryptionDlg::OnBnClickedButtonOpenfile()
{
	// TODO:
	CString str = _T("notepad.exe ");
	str += KEYFILE_NAME;
	::WinExec(str, SW_SHOW);
}


void CblowfishencryptionDlg::OnBnClickedButtonLog()
{
	// TODO:
	/*
	CString str = _T("notepad.exe ");
	str += KEYFILE_NAME;
	::WinExec(str, SW_SHOW);
	*/
}


void CblowfishencryptionDlg::OnBnClickedButtonDriver()
{
	// TODO:
/**
	ShellExecute(
		NULL,
		"open",
		"sc",
		"start encryptengine",
		NULL,
		SW_HIDE
		);

*/

	CString csCaption;
	GetDlgItemText(IDC_BUTTON_DRIVER,csCaption);

	if(csCaption == "fff")
	{
		SetDlgItemText(IDC_BUTTON_DRIVER,"ggggggg");



		ShellExecute(
			NULL,
			"open",
			"sc",
			"start encryptengine",
			NULL,
			SW_HIDE
			);

	}

	if(csCaption == "lllll")
	{
		SetDlgItemText(IDC_BUTTON_DRIVER,"kkkkk");
		ShellExecute(
			NULL,
			"open",
			"sc",
			"stop encryptengine",
			NULL,
			SW_HIDE
			);
	}

}
