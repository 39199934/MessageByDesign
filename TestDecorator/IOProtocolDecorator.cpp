#include "IOProtocolDecorator.h"

IOProtocolDecorator::IOProtocolDecorator(IOProtocol* parent)
	:IOProtocol(),
	widget(parent)
{
}

IOProtocolDecorator::~IOProtocolDecorator()
{
	//qDebug() << "in ~IOProtocolDecorator";
}

QByteArray IOProtocolDecorator::input()
{
	return widget->input();
	
}

void IOProtocolDecorator::output()
{
	widget->output();
}

void IOProtocolDecorator::outputOrigin()
{
	widget->outputOrigin();
}
