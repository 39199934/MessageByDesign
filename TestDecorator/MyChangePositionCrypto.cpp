#include "MyChangePositionCrypto.h"



QString MyChangePositionCrypto::description()
{
	return QString("changePositionCrypto");
}

unsigned char* MyChangePositionCrypto::bitEncoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	for (int i = 0; i < len; i++) {
		swap(p);
		p++;
	}
	return pp;
}


void MyChangePositionCrypto::swap(unsigned char * p) {
	int lowBit = *p & 0xF; //得到低四位
	int highBit = *p & 0xF0; //得到高四位
	*p = (lowBit << 4 | highBit >> 4);
}

unsigned char* MyChangePositionCrypto::bitDecoderMethod(unsigned char* p)
{
	auto pp = p;
	auto len = strlen((char*)p);
	for (int i = 0; i < len; i++) {
		swap(p);
		p++;
	}
	return pp;
}
