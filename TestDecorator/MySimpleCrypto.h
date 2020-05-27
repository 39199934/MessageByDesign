#pragma once
#include "MyCryptoProtocol.h"
class MySimpleCrypto :public MyCryptoProtocol
{
public:
	MySimpleCrypto();
public:

	virtual QByteArray doEncoder(QByteArray uncrypto_bytes) override;
	virtual  QByteArray doDecoder(QByteArray cryptoed_bytes) override;
	virtual QString description() override;
private:
	int key = 64;
	QByteArray simpleMethod(QByteArray bytes);
};

