#pragma once

class CEncDesProtocol
{
public:
	CEncDesProtocol()
	{
	
	}
	virtual ~CEncDesProtocol()
	{
	
	}
	virtual int EncData(unsigned char* plain, int plainint, unsigned char* cryData, int* crylen) = 0;
	virtual int DecData(unsigned char* cryData, int crylen, unsigned char* plain, int* plainint) = 0;

};