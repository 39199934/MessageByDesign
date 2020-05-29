#include "MyMoveCrypto.h"

QByteArray MyMoveCrypto::doEncoder(QByteArray uncrypto_bytes)
{
	auto newBytes = uncrypto_bytes;
	//createBytesData(newBytes);
	auto data = uncrypto_bytes.data();
	auto len = strlen(data);
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;
	for (int i = 0; i < len; i++) {
		if (*mp & key) {
			*mp = *mp << 1;
			*mp += 1;
		}
		else {
			*mp = *mp << 1;
		}
		mp++;
	}
	mp[len] = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes = QByteArray::fromRawData((char*)pmp, len);
	return newBytes;
	
}

QByteArray MyMoveCrypto::doDecoder(QByteArray cryptoed_bytes)
{
	auto newBytes = cryptoed_bytes;
	//createBytesData(newBytes);
	auto data = cryptoed_bytes.data();
	auto len = strlen(data);
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;
	for (int i = 0; i < len; i++) {
		if (*mp & 1) {
			*mp = *mp >> 1;
			*mp += key;
		}
		else {
			*mp = *mp >> 1;
		}
		mp++;
	}
	mp[len] = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes = QByteArray::fromRawData((char*)pmp, len);
	return newBytes;
}

QString MyMoveCrypto::description()
{
	return QString("moveCrypto");
}
