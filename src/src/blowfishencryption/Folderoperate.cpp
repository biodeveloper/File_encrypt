#include "StdAfx.h"
#include "Folderoperate.h"
//#include"blowfishencryptionDlg.h"

Folderoperate::Folderoperate(void)
{
}


Folderoperate::~Folderoperate(void)
{
}
//
CString Folderoperate::openFloder()
{
	BROWSEINFO info;//
	memset(&info,0,sizeof(BROWSEINFO));//
	CWnd m_hWnd;
	info.hwndOwner=m_hWnd;//
	info.lpszTitle="选择路径";
	LPCITEMIDLIST pidl;//
	pidl=SHBrowseForFolder(&info);//
	if (pidl==NULL)
	{
		return 0;
	}
	char pszPath[512];//
	if (!SHGetPathFromIDList(pidl,pszPath))//
	{
		AfxMessageBox("打开Folder路径失败");
		return 0;
	}
	return pszPath;
}
//
int Folderoperate:: EncDencFolder(bool mark,const char *sourcefile,const char *destfile,const char *pwd)
{
	strcpy(sourcefile1,sourcefile);
	strcpy(destfile1,destfile);
	strcpy(pwd1,pwd);
	CString readhash;//
	CString strminghash;//hash
	bool markhash=true;//
	bool bsrcisdirectory(false);//
	bool bdesisdirectory(false);//
	if(::GetFileAttributesA(sourcefile)&FILE_ATTRIBUTE_DIRECTORY)
		bsrcisdirectory=true;//ture
	if(::GetFileAttributesA(destfile)&FILE_ATTRIBUTE_DIRECTORY)
		bdesisdirectory=true;//ture
	CFileFind filefind1;//
	
		//CString strfoldername=sourcefile1.Right(strold.GetLength()-strold.ReverseFind('\\')-1);
		//
		//CString strfind=strcpy(sourcefile1,"\\*.*");//
	     CString str=sourcefile1;
	     CString strfind=str+"\\*.*";
		bool bfind=filefind1.FindFile(strfind);//
		while(bfind)
		{
			bfind=filefind1.FindNextFileA();//
			if (filefind1.IsDirectory())//
			{
				if(filefind1.IsDots()) continue;//
				CString srcfilepath=filefind1.GetFilePath();
				CString desfilepath=srcfilepath;
				EncDencFolder(mark,srcfilepath,desfilepath,pwd);//
			}
			else//
			{
				CString srcfilepath;
				CString desfilepath;
				if(mark==true)//
				{
					 srcfilepath=filefind1.GetFilePath();

					 desfilepath=srcfilepath+".enc";
					CString strhash= md5folder.md5file(srcfilepath);//
					running1.processing(mark,srcfilepath,desfilepath,pwd);//
					md5folder.writehashtofile(desfilepath,strhash);//
					running1.writemimatofile(desfilepath,pwd);//
					running1.clearing(srcfilepath);//
				     //
				}
				if(mark==false)//
				{  
					desfilepath=filefind1.GetFilePath();
					readmima=running1.readmimafromfile(desfilepath);//
					//
					 if(readmima!=pwd)
			          {
				         AfxMessageBox("输入密码错误，请重新输入密码");
				         return 1;
			          }
				    running1.rebackencfile(desfilepath,readmima.GetLength()+1);//?
				    readhash=md5folder.readhashfromfile(desfilepath);//hash
					running1.rebackencfile(desfilepath,32);//
					srcfilepath=desfilepath.Left(desfilepath.GetLength()-4);//
					running1.processing(mark,desfilepath,srcfilepath,pwd);//
				    strminghash=md5folder.md5file(srcfilepath);//hash
					running1.clearing(desfilepath);//
					//if(strminghash==readhash)
						//markhash=true;
					//	AfxMessageBox("grgrggrg");
					 if(strminghash!=readhash)
                      {
						  AfxMessageBox("efwfwf"+srcfilepath+"fffdfd");
						  markhash=false;
					 }

				}

			}
		} 
		if((markhash==true)&&(mark==false))
        AfxMessageBox("加密解密后，文件完整性良好");
		return 0;
}
//
int Folderoperate:: EncDencDESFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd_1,const char *pwd_2)
{
	strcpy(sourcefile1,soursefile);
	strcpy(destfile1,destfile);
	strcpy(pwd1,pwd_1);
	strcpy(pwd2,pwd_2);
	CString readhash;//存放从密文中读取的hash
	CString strminghash;//解密后明文的hash
	bool markhash=true;//标记文件完整的标记
	CFileFind filefind1;//声明MFC的文件查找对象
	CString str=sourcefile1;
	CString strfind=str+"\\*.*";
	bool bfind=filefind1.FindFile(strfind);//查找第一个符合的文件或文件夹
	while(bfind)
	{
		bfind=filefind1.FindNextFileA();//查找符合的下一个文件或文件夹
		if (filefind1.IsDirectory())//找到的是文件夹
		{
			if(filefind1.IsDots()) continue;//排除DOS系统自带的
			CString srcfilepath=filefind1.GetFilePath();
			CString desfilepath=srcfilepath;
			EncDencDESFolder(mark,srcfilepath,desfilepath,pwd1,pwd2);//递归调用加密子文件夹
		}
		else//找到的是文件
		{
			CString srcfilepath;
			CString desfilepath;
			if(mark==true)//如果为加密
			{
				srcfilepath=filefind1.GetFilePath();

				desfilepath=srcfilepath+".encD";
				CString strhash= md5folder.md5file(srcfilepath);//获取hash值
				running1.desprocess(mark,srcfilepath,desfilepath,pwd1,pwd2);//调用3DES加密处理函数
				md5folder.writehashtofile(desfilepath,strhash);//将hash写入到密文中
				running1.writemimatofile(desfilepath,pwd1);//将密码1写入到密文中
				char *str=";";
	            running1.writemimatofile(desfilepath,str);//用；分开两个密钥
			    running1.writemimatofile(desfilepath,pwd2);//将密码2写入到密文中
				running1.clearing(srcfilepath);//调用删除文件函数，删除源文件
				 //此处必能加return，否则就跳出循环
			}
			if(mark==false)//如果为解密
			{  
				desfilepath=filefind1.GetFilePath();
				readmima1=running1.readmimafromfile(desfilepath);//从密文中读取密码2
				readmima=running1.readmima1fromfile(desfilepath,readmima1.GetLength());//从密文中读取密码1
				//密码输入判断必须放在这个位置，如果密码不对，不能对密文做任何处理，否则无法解密，判断完后再还原密文
				if((readmima!=pwd1)&&(readmima1!=pwd2))
				{
					AfxMessageBox("输入密码错误，请重新输入密码");
					return 1;
				}
				running1.rebackencfile(desfilepath,readmima.GetLength()+readmima1.GetLength()+2);//删除密码，还原密文
				readhash=md5folder.readhashfromfile(desfilepath);//从密文中读取hash
				running1.rebackencfile(desfilepath,32);//删除密文结尾的hash值，便于进行解密
				srcfilepath=desfilepath.Left(desfilepath.GetLength()-5);//获得明文路径
				running1.desprocess(mark,desfilepath,srcfilepath,pwd1,pwd2);//调用解密函数
				strminghash=md5folder.md5file(srcfilepath);//获得解密文件的hash
				running1.clearing(desfilepath);//调用删除文件函数，删除源文件
				//if(strminghash==readhash)
					//markhash=true;
					//	AfxMessageBox("加密解密后，文件完整性良好");
					if(strminghash!=readhash)
					{
						AfxMessageBox("加密解密后，"+srcfilepath+"文件完整性被破坏");
						markhash=false;
					}

			}

		}
	}
	if((markhash==true)&&(mark==false))
		AfxMessageBox("加密解密后，文件完整性良好");
	return 0;

}
