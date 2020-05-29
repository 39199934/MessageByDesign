#pragma once
#include "MyCryptoProtocol.h"
#include <QString>
class MyChangePositionCrypto :
	public MyCryptoProtocol
{
public:


	virtual QString description() override;
	virtual unsigned char* bitEncoderMethod(unsigned char* p) override;
	static void swap(unsigned char* p);
	virtual unsigned char* bitDecoderMethod(unsigned char* p) override;
};

