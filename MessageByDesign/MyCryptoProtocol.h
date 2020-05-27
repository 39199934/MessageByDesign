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
	virtual QByteArray doEncoder( QByteArray uncrypto_bytes) =0;
	virtual  QByteArray doDecoder( QByteArray cryptoed_bytes) =0;
	virtual QString description()=0;
protected:
	//unsigned char* bytesData;
	//void createBytesData(QByteArray bytes);

private:
	
	//MyCryptoProtocol* createCryptoClass(MyCryptoType type);
};

