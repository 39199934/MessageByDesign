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

QString IOProtocolDecorator::input()
{
	return widget->input();
	return QString();
}

void IOProtocolDecorator::output()
{
	widget->output();
}

void IOProtocolDecorator::outputOrigin()
{
	widget->outputOrigin();
}
