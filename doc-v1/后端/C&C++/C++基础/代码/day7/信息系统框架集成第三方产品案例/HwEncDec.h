#pragma once
#include <iostream>
using namespace std;

#include "CEncDesProtocol.h"

class HwEncDec : public CEncDesProtocol
{
public:
	virtual int EncData(unsigned char* plain, int plainint, unsigned char* cryData, int* crylen);
	virtual int DecData(unsigned char* cryData, int crylen, unsigned char* plain, int* plainint);
private:
};