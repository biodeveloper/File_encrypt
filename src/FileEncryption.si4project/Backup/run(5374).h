#pragma once
#include "../yxyDES2/yxyDES2.h"
class run
{
public:
	run(void);
	~run(void);
	void processing(bool mark,const char *source, const char *dest, const char *pwd);//blowfish�ӽ��ܴ���
	void clearing(const char *clearfile);//ɾ��Դ�ļ�
	void writemimatofile(const char *mifilename, const char* pwd);//��������д������
	CString readmimafromfile(const char *mifilename);//��ȡ�����е�����
	CString readmima1fromfile(const char *mifilename,int lenght);//��ȡ�����е�����1
	void rebackencfile(const char *mifilename,int len);//��ԭ����
	void filldes(const char *mifilename,int len);//3DES���
	int readfill(const char *mingfilename);//��ȡ���λ��
	void desprocess(bool mark,const char *source, const char *dest, const char *pwd1,const char *pwd2);//3DES�ӽ��ܴ���
public:
	char _readFile[MAX_PATH];
	char _writeFile[MAX_PATH];
    char _password[100];
	
    char _password1[100];
	char _password2[100];
	yxyDES2 DES;

};

