#pragma once
#include "MyCryptoProtocol.h"
#include <QString>
class MyMoveCrypto :
	public MyCryptoProtocol
{
public:
	virtual QByteArray doEncoder(QByteArray uncrypto_bytes) override;
	virtual  QByteArray doDecoder(QByteArray cryptoed_bytes) override;
	virtual QString description() override;
private:
	int key = 128;
	//QByteArray simpleMethod(QByteArray bytes);
};

