#include "IOProtocolDecoratorCrypto.h"

IOProtocolDecoratorCrypto::IOProtocolDecoratorCrypto(IOProtocol* widget, MyCryptoProtocol* crypto_class )
	: IOProtocolDecorator(widget)
	,crypto(crypto_class)
{
	//widget->setWindowTitle("crypto widget");
	
}

IOProtocolDecoratorCrypto::~IOProtocolDecoratorCrypto()
{
	//qDebug() << "in ~IOProtocolDecoratorCrypto";
	/*if (widget != nullptr) {
		delete widget;
		widget = nullptr;
	}*/
}

QByteArray IOProtocolDecoratorCrypto::input()
{
	IOProtocolDecorator::input();
	text = widget->getText();
	//auto str = widget->input();
	text = crypto->doEncoder(text);
	//text = QString::fromLocal8Bit(by);
	//widget->setText(text);

	return text;
}

void IOProtocolDecoratorCrypto::output()
{
	
	//auto str = widget->getText();
	auto by = text;
	auto deby = crypto->doDecoder(by);
	//auto ntext = QString::fromLocal8Bit(deby);
	widget->setText(deby);
	IOProtocolDecorator::output();
	
	//widget->setText(text);
}

void IOProtocolDecoratorCrypto::outputOrigin()
{
	QString head;
	head = QString::fromLocal8Bit("加密方法：") + crypto->description() + QString::fromLocal8Bit("，密文：");
	widget->setText(head.toLocal8Bit()+text);
	IOProtocolDecorator::outputOrigin();
	//auto str = widget->getText();
	//widget->ui.cOriginOutput->setText(str);
}
