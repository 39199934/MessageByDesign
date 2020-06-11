#include "MySocket.h"

MySocket::MySocket(qintptr socket_description, SocketIMPProtocol* new_imp, QObject* parent)
	: QTcpSocket(parent),
	imp(new_imp)
{
	setSocketDescriptor(socket_description);
	connect(this, &QTcpSocket::stateChanged, this, &MySocket::slotStateIsChanged);
	connect(this, &QTcpSocket::readyRead, this, &MySocket::slotRecivedMessage);
	
}

MySocket::~MySocket()
{
	
		disconnect();
	
}

void MySocket::linkToHost()
{
	connectToHost(imp->getHostAddress(), imp->getHostPort());
}

void MySocket::disLinkToHost()
{
	disconnectFromHost();
}

SocketIMPProtocol* MySocket::getIMPWidget()
{
	return imp;
}

void MySocket::sendMessage()
{
	auto bytes = imp->getNewMessage();
	write(bytes);
}

void MySocket::slotStateIsChanged(QAbstractSocket::SocketState state)
{
	imp->viewSocketState(state);
}

void MySocket::slotRecivedMessage()
{
	auto bytes = readAll();
	imp->viewMessage(bytes);
}
