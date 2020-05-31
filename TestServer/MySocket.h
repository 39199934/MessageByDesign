#pragma once

#include <QtNetwork/QTcpSocket>
#include "SocketIMPProtocol.h"

class MySocket : public QTcpSocket
{
	Q_OBJECT

public:
	MySocket(SocketIMPProtocol* new_imp, QObject *parent = nullptr);
	~MySocket();
private:
	SocketIMPProtocol* imp;
};
