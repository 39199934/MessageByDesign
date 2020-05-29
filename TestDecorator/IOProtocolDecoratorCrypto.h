#pragma once

#include "IOProtocolDecorator.h"
#include "MySimpleCrypto.h"
#include "MyMoveCrypto.h"
#include "MyMoveLowerCrypto.h"
#include "MyChangePositionCrypto.h"
#include "MyMoveTextCrypto.h"
#include "MyXORCrypto.h"

class IOProtocolDecoratorCrypto : public IOProtocolDecorator
{


public:
	IOProtocolDecoratorCrypto(IOProtocol * widget,MyCryptoProtocol * crypto_class = new MyXORCrypto("lode"));
	~IOProtocolDecoratorCrypto();

	virtual QByteArray input() override;
	virtual void output() override;
	virtual void outputOrigin();
private:
	MyCryptoProtocol* crypto;
	//MyXORCrypto crypto;

};
