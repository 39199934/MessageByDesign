#include "MyCryptoBuilder.h"

MyCryptoBuilder::MyCryptoBuilder(MyCryptoProtocol::MyCryptoType type):
	crypto(nullptr)
{
	buildCryptoClass(type);
}

MyCryptoBuilder::~MyCryptoBuilder()
{
	if (crypto != nullptr) {
		delete crypto;
	}
}

QByteArray MyCryptoBuilder::encoder(QByteArray uncrypto_bytes)
{
	return crypto->doEncoder(uncrypto_bytes);
}

QByteArray MyCryptoBuilder::decoder(QByteArray cryptoed_bytes)
{
	return crypto->doDecoder(cryptoed_bytes);
}


MyCryptoProtocol* MyCryptoBuilder::buildCryptoClass(MyCryptoProtocol::MyCryptoType type)
{
	//MyCryptoProtocol* crypto;
	switch (type)
	{

	case MyCryptoProtocol::simple:
		crypto = new MySimpleCrypto();
		break;
	case MyCryptoProtocol::high:
		break;
	case MyCryptoProtocol::low:
		break;
	default:
		crypto = new MySimpleCrypto();
		break;
	}
	return crypto;
}
