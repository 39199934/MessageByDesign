#pragma once

#include "IOWidget.h"
#include "IOProtocol.h"

class IOProtocolDecorator : public IOProtocol
{


public:
	IOProtocolDecorator(IOProtocol *parent);
	~IOProtocolDecorator();

	virtual QByteArray input() override;
	virtual void output() override;
	virtual void outputOrigin();
protected:
	IOProtocol* widget;
};
