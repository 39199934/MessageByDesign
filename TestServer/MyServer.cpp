#include "MyServer.h"


MyServer::MyServer(QObject *parent)
	: QTcpServer(parent)
{
	//connect(this, &QTcpServer::newConnection, this, &MyServer::slotNewClientComming);
	listen(QHostAddress::Any,5667);
}

MyServer::~MyServer()
{
}

void MyServer::incomingConnection(qintptr socket_des)
{
	SocketIMPWidget* widget = new SocketIMPWidget();
	MySocket* socket = new MySocket(socket_des, widget, this);
	socket->sendMessage();
	widget->show();
}

void MyServer::slotNewClientComming()
{
	auto cli = nextPendingConnection();
	//MySocket* socket = new MySocket(new SocketIMPWidget());
	//socket->setSocketDescriptor(cli->socketDescriptor());
	
}
