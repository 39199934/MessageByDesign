#pragma once
#include <QString>
#include <QByteArray>
#include <QtNetwork/QAbstractSocket>
class SocketIMPProtocol
{
protected:
	virtual QByteArray getNewMessage() =0;
	virtual void viewMessage(const QByteArray& new_message) = 0;
	virtual void viewSocketState(QAbstractSocket::SocketState state) = 0;
	virtual void clearMessageHistory() = 0;
	virtual QString getHostAddress() = 0;
	virtual qint16 getHostPort() = 0;
};

