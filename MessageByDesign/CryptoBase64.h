#pragma once

#include "BodyOfMessageProtocol.h"
#include "CryptoBodyProtocol.h"

class CryptoBase64 : public CryptoBodyProtocol
{
	Q_OBJECT

public:
	CryptoBase64(BodyOfMessageProtocol* body_for_crypto, QObject *parent);
	~CryptoBase64();

	virtual void setBagByteArray(const QByteArray& bytes) override;
	virtual QByteArray getBagByteArray() override;
	//virtual HeadOfMessage* buildHead();
	virtual QString getCryptoType() override;
	//virtual QString getBodyType() ;
	//virtual void view(QTextBrowser* browser) override;
private:
	//BodyOfMessageProtocol* body;
};
