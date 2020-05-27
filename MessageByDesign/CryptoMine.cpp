#include "CryptoMine.h"
#define key 64
CryptoMine::CryptoMine(BodyOfMessageProtocol* body_for_crypto, QObject* parent)
	:CryptoBodyProtocol(body_for_crypto, parent)
{
	this->setBagByteArray(body_for_crypto->getBagByteArray());
}

CryptoMine::~CryptoMine()
{
}

void CryptoMine::setBagByteArray(const QByteArray& bytes)
{
	if (bytes.size() > 0) {
		//bytes.at(0) += 1;
		
		auto pData = bytes.data();
		qDebug() << pData;
		char* p = new char[strlen(pData)]();
		memcpy_s(p, strlen(pData), pData, strlen(pData));
	
		//strcpy_s(p, strlen(pData), pData);
		p[strlen(pData)] = '\0';
		char* mp = p;
		for (int i = 0; i < strlen(pData); i++) {
			if (*mp & key) {
				*mp -= key;
			}
			else {
				*mp += key;
			}
			mp++;
		}
		//*p += 1;
		qDebug() << p;
		auto nbytes = QByteArray(p);
		BagProtocol::setBagByteArray(nbytes);
		delete[] p;
		
	}

	BagProtocol::setBagByteArray(bytes);
}

QByteArray CryptoMine::getBagByteArray()
{
	auto bytes = getOriginalByteArray();
	if (bytes.size() > 0) {
		//bytes.at(0) += 1;

		auto pData = bytes.data();
		qDebug() << pData;
		char* p = new char[strlen(pData)]();
		memcpy_s(p, strlen(pData), pData, strlen(pData));
		
		p[strlen(pData)] = '\0';
		char* mp = p;
		for (int i = 0; i < strlen(pData); i++) {
			if (*mp & key) {
				*mp -= key;
			}
			else {
				*mp += key;
			}
			mp++;
		}
		//*p += 1;
		qDebug() << p;
		auto nbytes = QByteArray(p);
		return nbytes;
		//BagProtocol::setBagByteArray(nbytes);

	}
	return QByteArray();
}

QString CryptoMine::getCryptoType()
{
	return "mine";
}
