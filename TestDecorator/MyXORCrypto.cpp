#include "MyXORCrypto.h"

MyXORCrypto::MyXORCrypto(const QByteArray& new_key) :
	key(new_key)
{
}

QString MyXORCrypto::description()
{
	return QString("XORCrypto");
}

unsigned char* MyXORCrypto::bitEncoderMethod(unsigned char* p)
{
	auto pp = p;
	auto keyP = key.constData();
	auto len = strlen((char*)p);
	auto keyLen = strlen(keyP);
	unsigned char* temp = new unsigned char[len]();
	int arr = len / keyLen;
	int ys =0;
	if (arr > 0) {
		ys = len % keyLen;
	}
	else {
		ys = len;
	}
	for (int i = 0; i < arr; i++) {
		for (int j = 0; j < keyLen; j++) {
			int posi = i * keyLen + j;
			if (p[posi] == keyP[j]) {
				temp[posi] = p[posi];
			}
			else {
				temp[posi] = p[posi] ^ keyP[j];
			}
		}


	}
	//if ((ys > 0) && (arr >= 1)) {
	if ((ys > 0)) {
		for (int j = 0; j < ys; j++) {
			int posi = arr * keyLen + j;
			if (p[posi] == keyP[j]) {
				temp[posi] = p[posi];
			}
			else {
				temp[posi] = p[posi] ^ keyP[j];
			}
		}
	}
	temp[len] = '\0';
	memcpy_s(pp, len, temp, len);
	return pp;
}

unsigned char* MyXORCrypto::bitDecoderMethod(unsigned char* p)
{
	auto pp = p;
	auto keyP = key.constData();
	auto len = strlen((char*)p);
	auto keyLen = strlen(keyP);
	unsigned char* temp = new unsigned char[len]();
	int arr = len / keyLen;
	int ys = 0;
	if (arr > 0) {
		ys = len % keyLen;
	}
	else {
		ys = len;
	}
	for (int i = 0; i < arr; i++) {
		for (int j = 0; j < keyLen; j++) {
			int posi = i * keyLen + j;
			if (p[posi] == keyP[j]) {
				temp[posi] = p[posi];
			}
			else {
				temp[posi] = p[posi] ^ keyP[j];
			}
		}


	}
	//if ((ys > 0) && (arr >= 1)) {
	if ((ys > 0)) {
		for (int j = 0; j < ys; j++) {
			int posi = arr * keyLen + j;
			if (p[posi] == keyP[j]) {
				temp[posi] = p[posi];
			}
			else {
				temp[posi] = p[posi] ^ keyP[j];
			}
		}
	}
	temp[len] = '\0';
	memcpy_s(pp, len, temp, len);
	return pp;
}
/*
QByteArray MyXORCrypto::bitEncoderTemple(QByteArray bytes)
{
	QByteArray newBytes ;
	//createBytesData(newBytes);
	auto data = bytes.data();
	auto len = strlen(data);
	newBytes.append("XOR");
	char* strToLen = new char[sizeof(int)]();
	memcpy_s(strToLen, sizeof(int), &len, sizeof(int));
	newBytes.append(strToLen, sizeof(int));
	//newBytes.append()
	unsigned char* mp = new unsigned char[strlen(data)]();
	memcpy_s(mp, len, data, len);
	mp[len] = '\0';
	unsigned char* pmp = mp;

	this->bitEncoderMethod(mp);


	mp[len] = '\0';
	//qDebug() << "cryptoed:"<<bytesData;
	newBytes.append((char*)pmp, len);
	return newBytes;
}

*/
