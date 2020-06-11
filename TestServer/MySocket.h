#pragma once

#include <QtNetwork/QTcpSocket>
#include <QAbstractSocket>
#include "SocketIMPProtocol.h"
#include "SocketIMPWidget.h"

class MySocket : public QTcpSocket
{
	Q_OBJECT

public:
	MySocket(qintptr socket_description, SocketIMPProtocol* new_imp, QObject *parent = nullptr);
	virtual ~MySocket();
	void linkToHost();
	void disLinkToHost();
	SocketIMPProtocol* getIMPWidget();
	void sendMessage();
private:
	SocketIMPProtocol* imp;
protected slots:
	void slotRecivedMessage();
	void slotStateIsChanged(QAbstractSocket::SocketState state);
	

};
