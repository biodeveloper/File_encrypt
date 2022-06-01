#pragma once
#include "../myDES2/myDES2.h"
class run
{
public:
	run(void);
	~run(void);
	void processing(bool mark,const char *source, const char *dest, const char *pwd);//blowfish
	void clearing(const char *clearfile);//
	void writemimatofile(const char *mifilename, const char* pwd);//
	CString readmimafromfile(const char *mifilename);//
	CString readmima1fromfile(const char *mifilename,int lenght);//
	void rebackencfile(const char *mifilename,int len);//
	void filldes(const char *mifilename,int len);//
	int readfill(const char *mingfilename);//
	void desprocess(bool mark,const char *source, const char *dest, const char *pwd1,const char *pwd2);//
public:
	char _readFile[MAX_PATH];
	char _writeFile[MAX_PATH];
    char _password[100];
	
    char _password1[100];
	char _password2[100];
	myDES2 DES;

};

