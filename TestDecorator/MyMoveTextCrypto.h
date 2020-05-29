#pragma once
#include "MyCryptoProtocol.h"
#include <QString>
class MyMoveTextCrypto :
	public MyCryptoProtocol
{
public:
	virtual QString description() override;
	virtual unsigned char* bitEncoderMethod(unsigned char* p) override;
	virtual unsigned char* bitDecoderMethod(unsigned char* p) override;
};

