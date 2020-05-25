#pragma once
#include "BodyOfMessageProtocol.h"
#include "CryptoBodyProtocol.h"

class CryptoMine : public CryptoBodyProtocol
{
	Q_OBJECT

public:
	CryptoMine(BodyOfMessageProtocol* body_for_crypto, QObject *parent);
	~CryptoMine();

	virtual void setBagByteArray(const QByteArray& bytes) override;
	virtual QByteArray getBagByteArray() override;
	virtual QString getCryptoType() override;
};
