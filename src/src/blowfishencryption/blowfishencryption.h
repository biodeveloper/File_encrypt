
// blowfishencryption.h 
//

#pragma once

#ifndef __AFXWIN_H__
	#error "error"
#endif

#include "resource.h"		


// CblowfishencryptionApp:
//  blowfishencryption.cpp
//

class CblowfishencryptionApp : public CWinApp
{
public:
	CblowfishencryptionApp();

// 
public:
	virtual BOOL InitInstance();

// 

	DECLARE_MESSAGE_MAP()
};

extern CblowfishencryptionApp theApp;