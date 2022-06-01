#pragma once
#include "stdafx.h"

class FileFilter
{
public:
	 FileFilter(void);
	~FileFilter(void);


		CEdit m_edit;
	CEdit m_total;
	CEdit m_type_total;

	//
	CString	FilePath;

	int total;
	int typetotal;
	// 
	void GetFolderFilesCount(LPCTSTR pPathName);
	// 
	void FindFiles(CString sPath);
	CListCtrl m_typelist;
	CStringArray typeArray;
	struct typeCount{
		CString type;
		int num;
	}TypeCount[1000];
	bool newtypeFlag;
	void showtype();

     void GetFolderFilesCount(LPCTSTR pPathName);
	 void FindFiles(CString sPath);
	 void showtype();
}