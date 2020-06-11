#include "TestTcpSocket.h"
#include <QtWidgets/QApplication>
#include "ClientProtocol.h"
#include "ClientIMPOnWidget.h"
#include "ClientIMPOnStd.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestTcpSocket w;
	ClientIMPProtocol* widget = new ClientIMPOnWidget();
	ClientProtocol client(widget);
	client.connectToHost("127.0.0.1", 5666);
	widget->setNotification(&client);
	widget->showWidget();
	//w.show();
	return a.exec();
}
