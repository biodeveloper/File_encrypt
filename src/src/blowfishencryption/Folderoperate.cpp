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
	info.lpszTitle="ѡ��·��";
	LPCITEMIDLIST pidl;//
	pidl=SHBrowseForFolder(&info);//
	if (pidl==NULL)
	{
		return 0;
	}
	char pszPath[512];//
	if (!SHGetPathFromIDList(pidl,pszPath))//
	{
		AfxMessageBox("��Folder·��ʧ��");
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
				         AfxMessageBox("�������������������������");
				         return 1;
			          }
				    running1.rebackencfile(desfilepath,readmima.GetLength()+1);//�
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
        AfxMessageBox("���ܽ��ܺ��ļ�����������");
		return 0;
}
//
int Folderoperate:: EncDencDESFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd_1,const char *pwd_2)
{
	strcpy(sourcefile1,soursefile);
	strcpy(destfile1,destfile);
	strcpy(pwd1,pwd_1);
	strcpy(pwd2,pwd_2);
	CString readhash;//��Ŵ������ж�ȡ��hash
	CString strminghash;//���ܺ����ĵ�hash
	bool markhash=true;//����ļ������ı��
	CFileFind filefind1;//����MFC���ļ����Ҷ���
	CString str=sourcefile1;
	CString strfind=str+"\\*.*";
	bool bfind=filefind1.FindFile(strfind);//���ҵ�һ�����ϵ��ļ����ļ���
	while(bfind)
	{
		bfind=filefind1.FindNextFileA();//���ҷ��ϵ���һ���ļ����ļ���
		if (filefind1.IsDirectory())//�ҵ������ļ���
		{
			if(filefind1.IsDots()) continue;//�ų�DOSϵͳ�Դ���
			CString srcfilepath=filefind1.GetFilePath();
			CString desfilepath=srcfilepath;
			EncDencDESFolder(mark,srcfilepath,desfilepath,pwd1,pwd2);//�ݹ���ü������ļ���
		}
		else//�ҵ������ļ�
		{
			CString srcfilepath;
			CString desfilepath;
			if(mark==true)//���Ϊ����
			{
				srcfilepath=filefind1.GetFilePath();

				desfilepath=srcfilepath+".encD";
				CString strhash= md5folder.md5file(srcfilepath);//��ȡhashֵ
				running1.desprocess(mark,srcfilepath,desfilepath,pwd1,pwd2);//����3DES���ܴ�����
				md5folder.writehashtofile(desfilepath,strhash);//��hashд�뵽������
				running1.writemimatofile(desfilepath,pwd1);//������1д�뵽������
				char *str=";";
	            running1.writemimatofile(desfilepath,str);//�ã��ֿ�������Կ
			    running1.writemimatofile(desfilepath,pwd2);//������2д�뵽������
				running1.clearing(srcfilepath);//����ɾ���ļ�������ɾ��Դ�ļ�
				 //�˴����ܼ�return�����������ѭ��
			}
			if(mark==false)//���Ϊ����
			{  
				desfilepath=filefind1.GetFilePath();
				readmima1=running1.readmimafromfile(desfilepath);//�������ж�ȡ����2
				readmima=running1.readmima1fromfile(desfilepath,readmima1.GetLength());//�������ж�ȡ����1
				//���������жϱ���������λ�ã�������벻�ԣ����ܶ��������κδ��������޷����ܣ��ж�����ٻ�ԭ����
				if((readmima!=pwd1)&&(readmima1!=pwd2))
				{
					AfxMessageBox("�������������������������");
					return 1;
				}
				running1.rebackencfile(desfilepath,readmima.GetLength()+readmima1.GetLength()+2);//ɾ�����룬��ԭ����
				readhash=md5folder.readhashfromfile(desfilepath);//�������ж�ȡhash
				running1.rebackencfile(desfilepath,32);//ɾ�����Ľ�β��hashֵ�����ڽ��н���
				srcfilepath=desfilepath.Left(desfilepath.GetLength()-5);//�������·��
				running1.desprocess(mark,desfilepath,srcfilepath,pwd1,pwd2);//���ý��ܺ���
				strminghash=md5folder.md5file(srcfilepath);//��ý����ļ���hash
				running1.clearing(desfilepath);//����ɾ���ļ�������ɾ��Դ�ļ�
				//if(strminghash==readhash)
					//markhash=true;
					//	AfxMessageBox("���ܽ��ܺ��ļ�����������");
					if(strminghash!=readhash)
					{
						AfxMessageBox("���ܽ��ܺ�"+srcfilepath+"�ļ������Ա��ƻ�");
						markhash=false;
					}

			}

		}
	}
	if((markhash==true)&&(mark==false))
		AfxMessageBox("���ܽ��ܺ��ļ�����������");
	return 0;

}
