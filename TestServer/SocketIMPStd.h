#pragma once
#include "SocketIMPProtocol.h"
#include <iostream>
#include <QDebug>
using namespace std;
class SocketIMPStd :
	public SocketIMPProtocol
{
	// ͨ�� SocketIMPProtocol �̳�
	virtual QByteArray getNewMessage() override;
	virtual void viewMessage(const QByteArray& new_message) override;
	virtual void viewSocketState(QAbstractSocket::SocketState state) override;
	virtual void clearMessageHistory() override;
	virtual QString getHostAddress() override;
	virtual qint16 getHostPort() override;
};

