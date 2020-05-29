#include "MyMoveLowerCrypto.h"

QByteArray MyMoveLowerCrypto::doEncoder(QByteArray uncrypto_bytes)
{
	return bitEncoderTemple(uncrypto_bytes);
}

QByteArray MyMoveLowerCrypto::doDecoder(QByteArray cryptoed_bytes)
{
	return bitDecoderTemple(cryptoed_bytes);
}

QString MyMoveLowerCrypto::description()
{
	return QString("moveLowerCrypto");
}

unsigned char* MyMoveLowerCrypto::bitEncoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	for (int i = 0; i < len; i++) {
		if (*p & 128) {
			*p = *p << 1;
			*p += 1;
			
		}
		else {
			*p = *p << 1;
		}
		p++;
	}
	return pp;
}

unsigned char* MyMoveLowerCrypto::bitDecoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	for (int i = 0; i < len; i++) {
		if (*p & 1) {
			*p = *p >> 1;
			*p += 128;
		}
		else {
			*p = *p >> 1;
		}
		p++;
	}
	return pp;
}
