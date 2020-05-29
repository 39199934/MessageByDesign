#pragma once
#include "MyCryptoProtocol.h"
#include <QString>
class MyMoveLowerCrypto :
	public MyCryptoProtocol
{
public:

	virtual QByteArray doEncoder(QByteArray uncrypto_bytes) override;
	virtual  QByteArray doDecoder(QByteArray cryptoed_bytes) override;
	virtual QString description() override;
	virtual unsigned char* bitEncoderMethod(unsigned char* p) override;
	virtual unsigned char* bitDecoderMethod(unsigned char* p) override;
private:
	int key = 1;
};

