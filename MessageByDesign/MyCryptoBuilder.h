#pragma once
#include "MyCryptoProtocol.h"
#include "MySimpleCrypto.h"
class MyCryptoBuilder
{
public:
	MyCryptoBuilder(MyCryptoProtocol::MyCryptoType type);
	~MyCryptoBuilder();
	QByteArray encoder(QByteArray uncrypto_bytes);
	QByteArray decoder(QByteArray cryptoed_bytes);
	MyCryptoProtocol* buildCryptoClass(MyCryptoProtocol::MyCryptoType type );
private:
	MyCryptoProtocol* crypto;
};

