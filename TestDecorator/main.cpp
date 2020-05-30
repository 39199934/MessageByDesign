#include "TestDecorator.h"
#include <QtWidgets/QApplication>
#include "IOStd.h"
#include "IOWidget.h"
#include "IOProtocolDecorator.h"
#include "IOProtocolDecoratorCrypto.h"
#include "IOFile.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//IOProtocolDecorator iow(nullptr);
	//iow.show();

	//io->input();
	//io->output();
	qDebug() << sizeof(int);
	qDebug() << sizeof(char);
	char* str = new char[sizeof(int)]();
	int aa = 25;
	memcpy_s(str, sizeof(int), &aa, sizeof(int));
	int b = 0;
	memcpy_s(&b, sizeof(int), str, sizeof(int));
	qDebug() << "b = " << b;
	
	TestDecorator w;
	w.show();
	return a.exec();
}
