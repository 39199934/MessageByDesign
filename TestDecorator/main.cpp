#include "TestDecorator.h"
#include <QtWidgets/QApplication>
#include "IOStd.h"
#include "IOWidget.h"
#include "IOProtocolDecorator.h"
#include "IOProtocolDecoratorCrypto.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//IOProtocolDecorator iow(nullptr);
	//iow.show();

	//io->input();
	//io->output();
	TestDecorator w;
	w.show();
	return a.exec();
}
