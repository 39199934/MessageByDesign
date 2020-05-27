#include "MySimpleCrypto.h"
#include <QDebug>

MySimpleCrypto::MySimpleCrypto():
	MyCryptoProtocol()
{
}

QByteArray MySimpleCrypto::doEncoder(QByteArray uncrypto_bytes)
{
	return simpleMethod(uncrypto_bytes);
}

QByteArray MySimpleCrypto::doDecoder(QByteArray cryptoed_bytes)
{
	return simpleMethod(cryptoed_bytes);
}

QString MySimpleCrypto::description()
{
	return QString("simpleCrypto");
}

QByteArray MySimpleCrypto::simpleMethod(QByteArray bytes)
{
	auto newBytes = bytes;
	//createBytesData(newBytes);
	auto data = bytes.data();
	auto len = strlen(data);
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;
	for (int i = 0; i < len; i++) {
		if (*mp & key) {
			*mp -= key;
		}
		else {
			*mp += key;
		}
		mp++;
	}
	*mp = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes = QByteArray::fromRawData((char*)pmp,len);
	return newBytes;
}
