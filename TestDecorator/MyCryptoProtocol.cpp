#include "MyCryptoProtocol.h"
#include <QDebug>

MyCryptoProtocol::MyCryptoProtocol()
{
}

MyCryptoProtocol::~MyCryptoProtocol()
{
	
}
QByteArray MyCryptoProtocol::bitEncoderTemple(QByteArray bytes)
{
	auto newBytes = bytes;
	//createBytesData(newBytes);
	auto data = bytes.data();
	auto len = strlen(data);
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;

	this->bitEncoderMethod(mp);

	
	mp[len] = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes = QByteArray::fromRawData((char*)pmp, len);
	return newBytes;
}
QByteArray MyCryptoProtocol::bitDecoderTemple(QByteArray bytes)
{
	auto newBytes = bytes;
	//createBytesData(newBytes);
	auto data = bytes.data();
	auto len = strlen(data);
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;

	this->bitDecoderMethod(mp);


	mp[len] = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes = QByteArray::fromRawData((char*)pmp, len);
	return newBytes;
}
/*
QByteArray MyCryptoProtocol::encoder(MyCryptoType type, QByteArray uncrypto_bytes)
{
	MyCryptoBuilder builder;
	crypto = builder.buildCryptoClass(type);
	//createCryptoClass(type);
	return crypto->doEncoder(uncrypto_bytes);
	return QByteArray();
}

QByteArray MyCryptoProtocol::decoder(MyCryptoType type, QByteArray cryptoed_bytes)
{
	MyCryptoBuilder builder;
	crypto = builder.buildCryptoClass(type);
	return crypto ->doDecoder(cryptoed_bytes);
}

void MyCryptoProtocol::createBytesData(QByteArray bytes)
{
	qDebug() << "create bytes data"<<endl<<",the qbytearray = "<<bytes<<endl;
	qDebug() << "bytearray size" << bytes.size();
	auto data = bytes.data();

	qDebug()<<"create bytes = " << data;
	if (bytesData != nullptr) {
		delete[] bytesData;
	}
	bytesData = new unsigned char[strlen(data)]();
	qDebug() << "bytearray size" << bytes.size() << ",bytesdata strlen:" << strlen((char*)bytesData) << ",data strlen:" << strlen(data);
	memcpy_s(bytesData, strlen(data), data, strlen(data));
	bytesData[strlen(data)] = '\0';
	//bytesData = (unsigned char*)data;
}
/*
MyCryptoProtocol* MyCryptoProtocol::createCryptoClass(MyCryptoType type)
{
	if (crypto != nullptr) {
		delete crypto;
	}
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
}*/
