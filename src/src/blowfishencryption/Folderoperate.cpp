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
	info.lpszTitle="Ñ¡ÔñÂ·¾¶";
	LPCITEMIDLIST pidl;//
	pidl=SHBrowseForFolder(&info);//
	if (pidl==NULL)
	{
		return 0;
	}
	char pszPath[512];//
	if (!SHGetPathFromIDList(pidl,pszPath))//
	{
		AfxMessageBox("´ò¿ªFolderÂ·¾¶Ê§°Ü");
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
				         AfxMessageBox("ÊäÈëÃÜÂë´íÎó£¬ÇëÖØĞÂÊäÈëÃÜÂë");
				         return 1;
			          }
				    running1.rebackencfile(desfilepath,readmima.GetLength()+1);//É
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
        AfxMessageBox("¼ÓÃÜ½âÃÜºó£¬ÎÄ¼şÍêÕûĞÔÁ¼ºÃ");
		return 0;
}
//
int Folderoperate:: EncDencDESFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd_1,const char *pwd_2)
{
	strcpy(sourcefile1,soursefile);
	strcpy(destfile1,destfile);
	strcpy(pwd1,pwd_1);
	strcpy(pwd2,pwd_2);
	CString readhash;//´æ·Å´ÓÃÜÎÄÖĞ¶ÁÈ¡µÄhash
	CString strminghash;//½âÃÜºóÃ÷ÎÄµÄhash
	bool markhash=true;//±ê¼ÇÎÄ¼şÍêÕûµÄ±ê¼Ç
	CFileFind filefind1;//ÉùÃ÷MFCµÄÎÄ¼ş²éÕÒ¶ÔÏó
	CString str=sourcefile1;
	CString strfind=str+"\\*.*";
	bool bfind=filefind1.FindFile(strfind);//²éÕÒµÚÒ»¸ö·ûºÏµÄÎÄ¼ş»òÎÄ¼ş¼Ğ
	while(bfind)
	{
		bfind=filefind1.FindNextFileA();//²éÕÒ·ûºÏµÄÏÂÒ»¸öÎÄ¼ş»òÎÄ¼ş¼Ğ
		if (filefind1.IsDirectory())//ÕÒµ½µÄÊÇÎÄ¼ş¼Ğ
		{
			if(filefind1.IsDots()) continue;//ÅÅ³ıDOSÏµÍ³×Ô´øµÄ
			CString srcfilepath=filefind1.GetFilePath();
			CString desfilepath=srcfilepath;
			EncDencDESFolder(mark,srcfilepath,desfilepath,pwd1,pwd2);//µİ¹éµ÷ÓÃ¼ÓÃÜ×ÓÎÄ¼ş¼Ğ
		}
		else//ÕÒµ½µÄÊÇÎÄ¼ş
		{
			CString srcfilepath;
			CString desfilepath;
			if(mark==true)//Èç¹ûÎª¼ÓÃÜ
			{
				srcfilepath=filefind1.GetFilePath();

				desfilepath=srcfilepath+".encD";
				CString strhash= md5folder.md5file(srcfilepath);//»ñÈ¡hashÖµ
				running1.desprocess(mark,srcfilepath,desfilepath,pwd1,pwd2);//µ÷ÓÃ3DES¼ÓÃÜ´¦Àíº¯Êı
				md5folder.writehashtofile(desfilepath,strhash);//½«hashĞ´Èëµ½ÃÜÎÄÖĞ
				running1.writemimatofile(desfilepath,pwd1);//½«ÃÜÂë1Ğ´Èëµ½ÃÜÎÄÖĞ
				char *str=";";
	            running1.writemimatofile(desfilepath,str);//ÓÃ£»·Ö¿ªÁ½¸öÃÜÔ¿
			    running1.writemimatofile(desfilepath,pwd2);//½«ÃÜÂë2Ğ´Èëµ½ÃÜÎÄÖĞ
				running1.clearing(srcfilepath);//µ÷ÓÃÉ¾³ıÎÄ¼şº¯Êı£¬É¾³ıÔ´ÎÄ¼ş
				 //´Ë´¦±ØÄÜ¼Óreturn£¬·ñÔò¾ÍÌø³öÑ­»·
			}
			if(mark==false)//Èç¹ûÎª½âÃÜ
			{  
				desfilepath=filefind1.GetFilePath();
				readmima1=running1.readmimafromfile(desfilepath);//´ÓÃÜÎÄÖĞ¶ÁÈ¡ÃÜÂë2
				readmima=running1.readmima1fromfile(desfilepath,readmima1.GetLength());//´ÓÃÜÎÄÖĞ¶ÁÈ¡ÃÜÂë1
				//ÃÜÂëÊäÈëÅĞ¶Ï±ØĞë·ÅÔÚÕâ¸öÎ»ÖÃ£¬Èç¹ûÃÜÂë²»¶Ô£¬²»ÄÜ¶ÔÃÜÎÄ×öÈÎºÎ´¦Àí£¬·ñÔòÎŞ·¨½âÃÜ£¬ÅĞ¶ÏÍêºóÔÙ»¹Ô­ÃÜÎÄ
				if((readmima!=pwd1)&&(readmima1!=pwd2))
				{
					AfxMessageBox("ÊäÈëÃÜÂë´íÎó£¬ÇëÖØĞÂÊäÈëÃÜÂë");
					return 1;
				}
				running1.rebackencfile(desfilepath,readmima.GetLength()+readmima1.GetLength()+2);//É¾³ıÃÜÂë£¬»¹Ô­ÃÜÎÄ
				readhash=md5folder.readhashfromfile(desfilepath);//´ÓÃÜÎÄÖĞ¶ÁÈ¡hash
				running1.rebackencfile(desfilepath,32);//É¾³ıÃÜÎÄ½áÎ²µÄhashÖµ£¬±ãÓÚ½øĞĞ½âÃÜ
				srcfilepath=desfilepath.Left(desfilepath.GetLength()-5);//»ñµÃÃ÷ÎÄÂ·¾¶
				running1.desprocess(mark,desfilepath,srcfilepath,pwd1,pwd2);//µ÷ÓÃ½âÃÜº¯Êı
				strminghash=md5folder.md5file(srcfilepath);//»ñµÃ½âÃÜÎÄ¼şµÄhash
				running1.clearing(desfilepath);//µ÷ÓÃÉ¾³ıÎÄ¼şº¯Êı£¬É¾³ıÔ´ÎÄ¼ş
				//if(strminghash==readhash)
					//markhash=true;
					//	AfxMessageBox("¼ÓÃÜ½âÃÜºó£¬ÎÄ¼şÍêÕûĞÔÁ¼ºÃ");
					if(strminghash!=readhash)
					{
						AfxMessageBox("¼ÓÃÜ½âÃÜºó£¬"+srcfilepath+"ÎÄ¼şÍêÕûĞÔ±»ÆÆ»µ");
						markhash=false;
					}

			}

		}
	}
	if((markhash==true)&&(mark==false))
		AfxMessageBox("¼ÓÃÜ½âÃÜºó£¬ÎÄ¼şÍêÕûĞÔÁ¼ºÃ");
	return 0;

}
