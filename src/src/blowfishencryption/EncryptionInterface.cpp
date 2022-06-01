#include "StdAfx.h"
#include "EncryptionInterface.h"


EncryptionInterface::EncryptionInterface(const char *pwd)
{   
	if ((!pwd) ) throw "Invalid processing constructor params.";
	strncpy(_encryptionKey, pwd, 99);
   _encryptionKey[99] = 0; //strncpy
}


EncryptionInterface::~EncryptionInterface()
{
	ZeroMemory(_encryptionKey, 100);
}
