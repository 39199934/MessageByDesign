#include "TestTcpSocket.h"

TestTcpSocket::TestTcpSocket(QWidget *parent)
	: QMainWindow(parent),
	server(new ServerProtocol(this))
{
	ui.setupUi(this);
	
	client = new ClientProtocol(nullptr);
	client->connectToHost();
	client->showWidget();
	
	server->listen(QHostAddress::Any, 5668);
	//widget->showWidget();
}

TestTcpSocket::~TestTcpSocket()
{
	
	if (client != nullptr) {
		client->deleteLater();
		//delete client;
		//client = nullptr;
	}
	if (server != nullptr) {
		 server->deleteLater();
		server = nullptr;
	}
}
