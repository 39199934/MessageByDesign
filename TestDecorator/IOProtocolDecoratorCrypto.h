#pragma once

#include "IOProtocolDecorator.h"
#include "MySimpleCrypto.h"

class IOProtocolDecoratorCrypto : public IOProtocolDecorator
{


public:
	IOProtocolDecoratorCrypto(IOProtocol * widget);
	~IOProtocolDecoratorCrypto();

	virtual QString input() override;
	virtual void output() override;
	virtual void outputOrigin();
private:
	
	MySimpleCrypto crypto;

};
