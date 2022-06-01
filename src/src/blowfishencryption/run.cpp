#include "StdAfx.h"
#include "run.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++
#include "EncryptionInterface.h"
#include "../myDES2/myDES2.h"
run::run(void)
{
}

run::~run(void)
{
}


void run::processing(bool mark,const char *source, const char *dest, const char *pwd)
{  
	
	strcpy(_readFile,source);
	strcpy(_writeFile,dest);
	strcpy(_password,pwd);
	FILE *readFile = fopen(_readFile, "rb");
	if (readFile == 0) 
	 AfxMessageBox("不能打开要加密的文件。");

	const size_t bufferSize = 64;
	int barSize = 0;

	// reaching the end of the file and getting position = getting file size (bytes).
	fseek(readFile, 0, SEEK_END);//
	barSize = ftell(readFile);//ftell
	fseek(readFile, 0, SEEK_SET);//
	if (barSize == -1) 
    AfxMessageBox("不能获取文件长度");//
	barSize = barSize / bufferSize;

	FILE *writeFile = fopen(_writeFile, "wb");
	if (writeFile == 0) 
	AfxMessageBox("写入文件失败.");//

	char readBuffer[bufferSize];
	char writeBuffer[bufferSize];
	size_t readRet = 0;

	BlowFishEnc encryption(_password);
	int encRet;
	

	while (!feof(readFile))//feof(fp)
	{
		//readRet = fread(pInPut, sizeof(char), barSize, readFile);//buffreSize sizeof(char)
		memset(readBuffer,0,64);
		readRet = fread(readBuffer, sizeof(char), bufferSize, readFile);

		if (mark==false) 
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
		else //如果为加密
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


void run::rebackencfile(const char *mifilename,int len)
{
	FILE *readFile = fopen(mifilename, "rb");//
	if (readFile == 0) 
	AfxMessageBox("不能打开要检测的文件。");//
	fseek(readFile,-len, SEEK_END);//
	int barSize = ftell(readFile);//ftell
	fseek(readFile, 0, SEEK_SET);//
	if (barSize == -1) 
    AfxMessageBox("不能获取文件长度");//
	//int barSize1 = barSize*8;//
	 char *poutPut = ( char *)malloc(barSize);//
	 fread(poutPut, sizeof(char), barSize, readFile);//barSize sizeof(char) barSize，barSize
     FILE *writeFile = fopen(mifilename, "wb");
	if (writeFile == 0) 
	AfxMessageBox("写入文件失败.");//
	fwrite(poutPut, sizeof(char), barSize, writeFile);
	if (poutPut)
	 {
		free(poutPut);   //

	 }
	fflush(writeFile);

	fclose(writeFile);
	fclose(readFile);

}

//
void run::writemimatofile(const char *mifilename, const char* pwd)
{
	FILE *writeFile = fopen(mifilename, "a");//
	if (writeFile == 0) 
	AfxMessageBox("写入文件失败.");//
	fseek(writeFile, 0, SEEK_END);//
	
	fwrite(pwd, sizeof(char), strlen(pwd), writeFile);//
	
	fflush(writeFile);
	fclose(writeFile);
	return ;
}

//
CString run:: readmimafromfile(const char *mifilename)
{
	FILE *readFile = fopen(mifilename, "rb");//
	if (readFile == 0) 
	 AfxMessageBox("不能打开要检测的文件。");//
	
	char mimalen[2];//
	int i=1;//
	
	while(strcmp(mimalen,";")!=0)//“；”
	{
     fseek(readFile, -i, SEEK_END);//
	 fread(mimalen, sizeof(char),1, readFile);//
	 mimalen[1]=0;//
	 i++;
	}
	 
	 char mima[100];
	 fread(mima, sizeof(char),i-2, readFile);//
	 mima[i-2]=0;//
	 fclose(readFile);
	 
	 return mima;
}

//1
CString run::readmima1fromfile(const char *mifilename,int lenght)
{
	FILE *readFile = fopen(mifilename, "rb");//
	if (readFile == 0) 
	 AfxMessageBox("rgrrt");//
	
	char mimalen[2];//
	int i=1;//
	
	while(strcmp(mimalen,";")!=0)//“；”,
	{
     fseek(readFile, -(lenght+1+i), SEEK_END);//
	 fread(mimalen, sizeof(char),1, readFile);//
	 mimalen[1]=0;//
	 i++;
	}
	 
	 char mima[100];
	 fread(mima, sizeof(char),i-2, readFile);//
	 mima[i-2]=0;//
	 fclose(readFile);
	 
	 return mima;
}

//3des
void run:: desprocess(bool mark,const char *source, const char *dest, const char *pwd1,const char *pwd2)
{
	strcpy(_readFile,source);
	strcpy(_writeFile,dest);
	strcpy(_password1,pwd1);
	strcpy(_password2,pwd2);
	char buff[8] = {0};
	size_t readRet = 0;

	FILE *readFile = fopen(_readFile, "rb");//
	if (readFile == 0) 
	 AfxMessageBox("不能打开要加密的文件。");//
	int barSize = 0;//
	// reaching the end of the file and getting position = getting file size (bytes).
	fseek(readFile, 0, SEEK_END);//
	barSize = ftell(readFile);//ftell
	if(mark==true)
	filldes(_readFile,barSize);//“；”
	fseek(readFile, 0, SEEK_SET);//
	if (barSize == -1) 
    AfxMessageBox("fgtnn");//

	FILE *writeFile = fopen(_writeFile, "wb");
	if (writeFile == 0) 
	AfxMessageBox("写入文件失败.");//
    DES.InitializeKey(_password1,0);
	DES.InitializeKey(_password2,1);
	if(mark==true)//
	{
		while(!feof(readFile))
		{
			memset(buff,0,8);
			readRet=fread(buff,sizeof(char),8,readFile);//
			DES.EncryptData(buff, 0);
			DES.DecryptData(DES.GetCiphertextInBytes(), 1);
			DES.EncryptData(DES.GetPlaintext(), 0);
			fwrite(DES.GetCiphertextInBytes(),sizeof(char),readRet,writeFile);//readRet读
		}

		fclose(readFile);
		fflush(writeFile);
		fclose(writeFile);
		return;
	}
	else if(mark==false)
	{
		while(!feof(readFile))
		{
			memset(buff,0,8);
			readRet=fread(buff,sizeof(char),8,readFile);//
			//D(key0)-E(key1)-D(key0)
			DES.DecryptData(buff, 0);
			DES.EncryptData(DES.GetPlaintext(), 1);
			DES.DecryptData(DES.GetCiphertextInBytes(), 0);
			fwrite(DES.GetPlaintext(),sizeof(char),readRet,writeFile);//readRet
			
		}
		fclose(readFile);
		fflush(writeFile);
		fclose(writeFile);
		int fill=readfill(_writeFile);//
		if(fill>1)//
		rebackencfile(_writeFile,fill-2);//
		return;
	}

}

//3DES
void run::filldes(const char *mifilename,int len)
{
	if(len%8==0)
		return;
	int fillnum=8-len%8;
	FILE *writeFile = fopen(mifilename, "a");
	if (writeFile == 0) 
		AfxMessageBox("des.");//
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

//
int run:: readfill(const char *mingfilename)
{
	FILE *readFile = fopen(mingfilename, "rb");//
	if (readFile == 0) 
		AfxMessageBox("不能打开要加密的文件。");//
	char mimalen[2]={0};//
	int i=1;//
	//fseek(readFile,-i, SEEK_END);//
	    fseek(readFile,-1, SEEK_END);//
		fread(mimalen, sizeof(char),1, readFile);//
	while(strcmp(mimalen,";")==0)//“；”
	{
		fseek(readFile,-i, SEEK_END);//
		fread(mimalen, sizeof(char),1, readFile);//
		mimalen[1]=0;//
		i++;
	}
	fclose(readFile);
	return i;
}
