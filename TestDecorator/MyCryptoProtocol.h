#pragma once
#include <QByteArray>

class MyCryptoProtocol
{
public:
	enum MyCryptoType {
		simple,high,low
	};
	MyCryptoProtocol();
	virtual ~MyCryptoProtocol();
	

public:
	virtual QByteArray doEncoder(QByteArray uncrypto_bytes) {
		return bitEncoderTemple(uncrypto_bytes);
	};
	virtual  QByteArray doDecoder(QByteArray cryptoed_bytes) {
		return bitDecoderTemple(cryptoed_bytes);
	};
	virtual QString description()=0;

	virtual unsigned char* bitEncoderMethod(unsigned char* p) { return p; };
	virtual unsigned char* bitDecoderMethod(unsigned char* p) { return p; };
	
	
	virtual QByteArray bitEncoderTemple(QByteArray bytes);
	
	virtual QByteArray bitDecoderTemple(QByteArray bytes);

	//QByteArray bitEncoderTemple(QByteArray bytes£¬int len);

	QByteArray bitDecoderTemple(QByteArray bytes,int len);

	
	
protected:
	//unsigned char* bytesData;
	//void createBytesData(QByteArray bytes);

private:
	
	//MyCryptoProtocol* createCryptoClass(MyCryptoType type);
};

