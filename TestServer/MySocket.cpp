#include "MySocket.h"

MySocket::MySocket(SocketIMPProtocol* new_imp, QObject *parent)
	: QTcpSocket(parent),
	imp(new_imp)
{
}

MySocket::~MySocket()
{
}
