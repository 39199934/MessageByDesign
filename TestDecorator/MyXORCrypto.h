#pragma once
#include "MyCryptoProtocol.h"
#include <QString>
class MyXORCrypto :
	public MyCryptoProtocol
{
public:
	MyXORCrypto(const QByteArray& key = "password");
	virtual QString description() override;
	virtual unsigned char* bitEncoderMethod(unsigned char* p) override;
	virtual unsigned char* bitDecoderMethod(unsigned char* p) override;
private:
	QByteArray key;
};

