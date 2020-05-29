#include "MyMoveTextCrypto.h"

QString MyMoveTextCrypto::description()
{
	return QString("moveTextCrypto");
}

unsigned char* MyMoveTextCrypto::bitEncoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	unsigned char* temp = new unsigned char[len]();
	int arr = len / 2;
	int ys = len % 2;
	for (int i = 0; i < arr; i++) {
		temp[i * 2] = p[i * 2 + 1];
		temp[i * 2 + 1] = p[i * 2];
		
	}
	if (ys == 1) {
		temp[len - 1] = p[len - 1];
	}
	temp[len] = '\0';
	memcpy_s(pp, len, temp, len);
	return pp;
}

unsigned char* MyMoveTextCrypto::bitDecoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	unsigned char* temp = new unsigned char[len]();
	int arr = len / 2;
	int ys = len % 2;
	for (int i = 0; i < arr; i++) {
		temp[i * 2] = p[i * 2 + 1];
		temp[i * 2 + 1] = p[i * 2];

	}
	if (ys == 1) {
		temp[len - 1] = p[len - 1];
	}
	temp[len] = '\0';
	memcpy_s(pp, len, temp, len);
	return pp;

}
