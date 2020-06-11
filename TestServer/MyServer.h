#pragma once

#include <QTcpServer>
#include "MySocket.h"

class MyServer : public QTcpServer
{
	Q_OBJECT

public:
	MyServer(QObject *parent);
	~MyServer();
private slots:
	void slotNewClientComming();
	virtual void incomingConnection(qintptr socket_des) override;
};
