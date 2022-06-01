
// _THE BlowFishEnc ENCRYPTION ALGORITHM_
// by Stefanos Metzidakis
//#include "stdafx.h"
//#include"resource.h"

#pragma once
#include "../blowfishencryption/stdafx.h"
#include "../blowfishencryption/EncryptionInterface.h"
//#include "EncryptionInterface.h"
class BlowFishEnc : public EncryptionInterface
{
public:
	 BlowFishEnc(const char *pwd);
	~BlowFishEnc();

	 DWORD encryptStream(const char *plain, const DWORD size, char *cipher);
	DWORD decryptStream(const char *cipher, const DWORD size, char *plain);

private:
	DWORD	GetOutputLength(DWORD lInputLong);

	DWORD 	*PArray;
	DWORD	(*SBoxes)[256];
	void 	BlowFishEnc_encipher(DWORD *xl, DWORD *xr);
	void 	BlowFishEnc_decipher(DWORD *xl, DWORD *xr);
};

union aword {
	DWORD dword;
	BYTE byte [4];
	struct {         
	unsigned int byte3:8;
	unsigned int byte2:8;
	unsigned int byte1:8;
	unsigned int byte0:8;
	} w;
};
