#include "TestTcpSocket.h"
#include <QtWidgets/QApplication>
#include "ClientProtocol.h"
#include "ClientIMPOnWidget.h"
#include "ClientIMPOnStd.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestTcpSocket w;
	
	w.show();
	return a.exec();
}
