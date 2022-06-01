#pragma once
#include<afx.h>
#include"stdafx.h"
#include"run.h"
#include "MD5.h"
class Folderoperate
{
public:
	Folderoperate(void);
	~Folderoperate(void);
	CString openFloder();//
	int EncDencFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd);//
	int EncDencDESFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd1,const char *pwd2);//
	int EncDencDBFolder(bool mark,const char *soursefile,const char *destfile,const char *pwd1,const char *pwd2);//
public:
	char sourcefile1[MAX_PATH];
	char destfile1[MAX_PATH];
	char pwd1[MAX_PATH];
	char pwd2[MAX_PATH];
	run running1;
	MD5 md5folder;
	CString readmima;
	CString readmima1;
};

