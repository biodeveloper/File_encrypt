#include "StdAfx.h"
#include "run.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++��ͬ�ļ����°���ͷ�ļ��ķ�����#include��ʹ����һ���Ĺ���
#include "EncryptionInterface.h"
#include "../yxyDES2/yxyDES2.h"
run::run(void)
{
}


run::~run(void)
{
}
//���ܽ��ܵĹ��̺���
void run::processing(bool mark,const char *source, const char *dest, const char *pwd)
{  
	
	strcpy(_readFile,source);
	strcpy(_writeFile,dest);
	strcpy(_password,pwd);
	FILE *readFile = fopen(_readFile, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
	 AfxMessageBox("���ܴ�Ҫ���ܵ��ļ���");//��ʧ��

	const size_t bufferSize = 64;
	int barSize = 0;//��¼��ȡ�ļ����ֽ���

	// reaching the end of the file and getting position = getting file size (bytes).����ļ�����
	fseek(readFile, 0, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	barSize = ftell(readFile);//ftell�õ���ʽ�ļ��ĵ�ǰ��дλ��,�䷵��ֵ�ǵ�ǰ��дλ��ƫ���ļ�ͷ�����ֽ���.
	fseek(readFile, 0, SEEK_SET);//���ļ�ָ���ƶ����ļ���ͷβ
	if (barSize == -1) 
    AfxMessageBox("���ܻ�ȡ�ļ�����");//���ܻ�ȡ�ļ��ֽ���
	barSize = barSize / bufferSize;

	FILE *writeFile = fopen(_writeFile, "wb");
	if (writeFile == 0) 
	AfxMessageBox("д���ļ�ʧ��.");//��ʧ��

	char readBuffer[bufferSize];
	char writeBuffer[bufferSize];
	size_t readRet = 0;

	BlowFishEnc encryption(_password);
	int encRet;
	

	while (!feof(readFile))//feof(fp)����������ֵ:��������ļ�����������feof��fp����ֵΪ1������Ϊ0��
	{
		//readRet = fread(pInPut, sizeof(char), barSize, readFile);//����buffreSize��sizeof(char)��С�Ŀ顣Ҳ����buffreSize�ֽ���
		memset(readBuffer,0,64);
		readRet = fread(readBuffer, sizeof(char), bufferSize, readFile);

		if (mark==false) //���Ϊ����
		{
			
            memset(writeBuffer,0,64);
			encRet = encryption.decryptStream(readBuffer, (DWORD)readRet, writeBuffer);
			if (feof(readFile))
			{
				int pos = 0;
				// removing trailing zeros - encrypted file must be x8 bytes.
				while ((pos < 8) && ((writeBuffer + encRet - pos)[0] == 0)) pos++;
				// if found trailing zeros - decreasing the writing buffer marker (not writing them).
				if (pos) encRet -= (pos - 1);
				
			}
		}
		else //���Ϊ����
		{
			//memset(readBuffer,0,1024);
			memset(writeBuffer,0,64);
			encRet = encryption.encryptStream(readBuffer, (DWORD)readRet, writeBuffer);
		}
		
		fwrite(writeBuffer, sizeof(char),encRet, writeFile);
		
		
	}
       // char *str=";";
	   // fwrite(str ,sizeof(char), 1, writeFile);
    fflush(writeFile);

	fclose(writeFile);
	fclose(readFile);
	
	ZeroMemory(writeBuffer, bufferSize);
	ZeroMemory(readBuffer, bufferSize);

}
//ɾ��Դ�ļ�
void run::clearing(const char *source)
{
	CString strdeletefile=source;
		if (!::DeleteFile(strdeletefile))
	  {
		int nerr=::GetLastError();
		AfxMessageBox("delete file wrong");
		return;
	  }

}




//��ԭ����
void run::rebackencfile(const char *mifilename,int len)
{
	FILE *readFile = fopen(mifilename, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
	AfxMessageBox("���ܴ�Ҫ�����ļ���");//��ʧ��
	fseek(readFile,-len, SEEK_END);//���ļ�ָ���ƶ���ɾ������ǰ
	int barSize = ftell(readFile);//Ҫ��ȡ���ֽ�����ftell�õ���ʽ�ļ��ĵ�ǰ��дλ��,�䷵��ֵ�ǵ�ǰ��дλ��ƫ���ļ�ͷ�����ֽ���.
	fseek(readFile, 0, SEEK_SET);//���ļ�ָ���ƶ����ļ���ͷ��
	if (barSize == -1) 
    AfxMessageBox("���ܻ�ȡ�ļ�����");//���ܻ�ȡ�ļ��ֽ���
	//int barSize1 = barSize*8;//�ļ���λ��
	 char *poutPut = ( char *)malloc(barSize);//�����ڴ�洢��ȡ�ļ�
	 fread(poutPut, sizeof(char), barSize, readFile);//����barSize��sizeof(char)��С�Ŀ顣Ҳ����barSize�ֽ��ˣ�barSizeΪ�ļ��ܳ��ȣ��൱��һ���Զ�ȡ�����ļ�
     FILE *writeFile = fopen(mifilename, "wb");
	if (writeFile == 0) 
	AfxMessageBox("д���ļ�ʧ��.");//��ʧ��
	fwrite(poutPut, sizeof(char), barSize, writeFile);
	if (poutPut)
	 {
		free(poutPut);   //�ͷ��ڴ�ռ�

	 }
	fflush(writeFile);

	fclose(writeFile);
	fclose(readFile);

}
//��������д������
void run::writemimatofile(const char *mifilename, const char* pwd)
{
	FILE *writeFile = fopen(mifilename, "a");//��д���ļ��ķ�ʽΪa��ԭ�����Դ���ע��д�뷽ʽ
	if (writeFile == 0) 
	AfxMessageBox("д���ļ�ʧ��.");//��ʧ��
	fseek(writeFile, 0, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	
	fwrite(pwd, sizeof(char), strlen(pwd), writeFile);//������д�뵽������
	
	fflush(writeFile);
	fclose(writeFile);
	return ;
}
//�������ж�ȡ����
CString run:: readmimafromfile(const char *mifilename)
{
	FILE *readFile = fopen(mifilename, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
	 AfxMessageBox("���ܴ�Ҫ�����ļ���");//��ʧ��
	
	char mimalen[2];//һ���ַ�һ���ַ��Ķ�ȡ���ַ������ڴ治��̫��
	int i=1;//��¼��ȡ���ַ�����
	
	while(strcmp(mimalen,";")!=0)//��������ֽ������������ֹͣ��ȡ�����ɵõ�i��ֵ
	{
     fseek(readFile, -i, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	 fread(mimalen, sizeof(char),1, readFile);//һ���ַ�һ���ַ��Ķ�ȡ
	 mimalen[1]=0;//���ַ���������־
	 i++;
	}
	 
	 char mima[100];
	 fread(mima, sizeof(char),i-2, readFile);//�������ж�����
	 mima[i-2]=0;//���ַ���������־
	 fclose(readFile);
	 
	 return mima;
}
//�������ж�ȡ��Կ1
CString run::readmima1fromfile(const char *mifilename,int lenght)
{
	FILE *readFile = fopen(mifilename, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
	 AfxMessageBox("���ܴ�Ҫ�����ļ���");//��ʧ��
	
	char mimalen[2];//һ���ַ�һ���ַ��Ķ�ȡ���ַ������ڴ治��̫��
	int i=1;//��¼��ȡ���ַ�����
	
	while(strcmp(mimalen,";")!=0)//��������ֽ������������ֹͣ��ȡ�����ɵõ�i��ֵ
	{
     fseek(readFile, -(lenght+1+i), SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	 fread(mimalen, sizeof(char),1, readFile);//һ���ַ�һ���ַ��Ķ�ȡ
	 mimalen[1]=0;//���ַ���������־
	 i++;
	}
	 
	 char mima[100];
	 fread(mima, sizeof(char),i-2, readFile);//�������ж�����
	 mima[i-2]=0;//���ַ���������־
	 fclose(readFile);
	 
	 return mima;
}









//3des�ļ��ӽ��ܴ�����
void run:: desprocess(bool mark,const char *source, const char *dest, const char *pwd1,const char *pwd2)
{
	strcpy(_readFile,source);
	strcpy(_writeFile,dest);
	strcpy(_password1,pwd1);
	strcpy(_password2,pwd2);
	char buff[8] = {0};
	size_t readRet = 0;

	FILE *readFile = fopen(_readFile, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
	 AfxMessageBox("���ܴ�Ҫ���ܵ��ļ���");//��ʧ��
	int barSize = 0;//��¼��ȡ�ļ����ֽ���
	// reaching the end of the file and getting position = getting file size (bytes).����ļ�����
	fseek(readFile, 0, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	barSize = ftell(readFile);//ftell�õ���ʽ�ļ��ĵ�ǰ��дλ��,�䷵��ֵ�ǵ�ǰ��дλ��ƫ���ļ�ͷ�����ֽ���.
	if(mark==true)
	filldes(_readFile,barSize);//��䡰����
	fseek(readFile, 0, SEEK_SET);//���ļ�ָ���ƶ����ļ���ͷβ
	if (barSize == -1) 
    AfxMessageBox("���ܻ�ȡ�ļ�����");//���ܻ�ȡ�ļ��ֽ���

	FILE *writeFile = fopen(_writeFile, "wb");
	if (writeFile == 0) 
	AfxMessageBox("д���ļ�ʧ��.");//��ʧ��
    DES.InitializeKey(_password1,0);
	DES.InitializeKey(_password2,1);
	if(mark==true)//���Ϊ����
	{
		while(!feof(readFile))
		{
			memset(buff,0,8);
			readRet=fread(buff,sizeof(char),8,readFile);//��¼��ȡ���ֽ���
			DES.EncryptData(buff, 0);
			DES.DecryptData(DES.GetCiphertextInBytes(), 1);
			DES.EncryptData(DES.GetPlaintext(), 0);
			fwrite(DES.GetCiphertextInBytes(),sizeof(char),readRet,writeFile);//readRet���˶��٣���д�����
		}

		fclose(readFile);
		fflush(writeFile);
		fclose(writeFile);
		return;
	}
	else if(mark==false)//���Ϊ����
	{
		while(!feof(readFile))
		{
			memset(buff,0,8);
			readRet=fread(buff,sizeof(char),8,readFile);//��¼��ȡ���ֽ���
			//D(key0)-E(key1)-D(key0)
			DES.DecryptData(buff, 0);
			DES.EncryptData(DES.GetPlaintext(), 1);
			DES.DecryptData(DES.GetCiphertextInBytes(), 0);
			fwrite(DES.GetPlaintext(),sizeof(char),readRet,writeFile);//readRet���˶��٣���д�����
			
		}
		fclose(readFile);
		fflush(writeFile);
		fclose(writeFile);
		int fill=readfill(_writeFile);//��ȡ���λ��
		if(fill>1)//�ж��Ƿ���������
		rebackencfile(_writeFile,fill-2);//��ԭ����
		return;
	}

}
//3DES���
void run::filldes(const char *mifilename,int len)
{
	if(len%8==0)
		return;
	int fillnum=8-len%8;
	FILE *writeFile = fopen(mifilename, "a");
	if (writeFile == 0) 
		AfxMessageBox("д���ļ�ʧ��.");//��ʧ��
	//char fillcontent[8]={0};
	//memset(fillcontent,0,9);
	CString fillcontent=";";
	int i;
	for(i=1;i<fillnum;i++)
	{
		fillcontent+=";";

	}
	//fillcontent[fillnum]='/0';
	fwrite(fillcontent,fillnum,1,writeFile);
	fflush(writeFile);
	fclose(writeFile);
	return;
}
//��ȡ���λ��
int run:: readfill(const char *mingfilename)
{
	FILE *readFile = fopen(mingfilename, "rb");//Ϊ����򿪶������ļ�
	if (readFile == 0) 
		AfxMessageBox("���ܴ�Ҫ���ܵ��ļ���");//��ʧ��
	char mimalen[2]={0};//һ���ַ�һ���ַ��Ķ�ȡ���ַ������ڴ治��̫��
	int i=1;//��¼��ȡ���ַ�����
	//fseek(readFile,-i, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
	    fseek(readFile,-1, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
		fread(mimalen, sizeof(char),1, readFile);//һ���ַ�һ���ַ��Ķ�ȡ
	while(strcmp(mimalen,";")==0)//����������ǡ�����ʱ����ֹͣ��ȡ�����ɵõ�i��ֵ
	{
		fseek(readFile,-i, SEEK_END);//���ļ�ָ���ƶ����ļ��Ľ�β
		fread(mimalen, sizeof(char),1, readFile);//һ���ַ�һ���ַ��Ķ�ȡ
		mimalen[1]=0;//���ַ���������־
		i++;
	}
	fclose(readFile);
	return i;
}