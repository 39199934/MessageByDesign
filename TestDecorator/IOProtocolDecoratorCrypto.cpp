#include "IOProtocolDecoratorCrypto.h"

IOProtocolDecoratorCrypto::IOProtocolDecoratorCrypto(IOProtocol* widget)
	: IOProtocolDecorator(widget)
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

QString IOProtocolDecoratorCrypto::input()
{
	IOProtocolDecorator::input();
	text = widget->getText();
	//auto str = widget->input();
	auto by = crypto.doEncoder(text.toLocal8Bit());
	text = QString::fromLocal8Bit(by);
	//widget->setText(text);

	return text;
}

void IOProtocolDecoratorCrypto::output()
{
	
	//auto str = widget->getText();
	auto by = text.toLocal8Bit();
	auto deby = crypto.doDecoder(by);
	auto ntext = QString::fromLocal8Bit(deby);
	widget->setText(ntext);
	IOProtocolDecorator::output();
	
	//widget->setText(text);
}

void IOProtocolDecoratorCrypto::outputOrigin()
{
	QString head;
	head = QString::fromLocal8Bit("加密方法：") + crypto.description() + QString::fromLocal8Bit("，密文：");
	widget->setText(head+text);
	IOProtocolDecorator::outputOrigin();
	//auto str = widget->getText();
	//widget->ui.cOriginOutput->setText(str);
}
