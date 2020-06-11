#pragma once

#include <QObject>
#include <QTcpSocket>
#include "ClientIMPProtocol.h"
#include "ClientIMPOnWidget.h"
#include "NotificationProtocol.h"

class ClientProtocol : public QTcpSocket,public NotificationProtocol
{
	Q_OBJECT

public:
	ClientProtocol(ClientIMPProtocol* new_imp,QObject *parent= nullptr);
	ClientProtocol(qintptr  socket_des, ClientIMPProtocol* new_imp, QObject* parent = nullptr);
	virtual ~ClientProtocol();
	void connectToHost();

private:
	ClientIMPProtocol* imp = nullptr;
	void slotOnClickedSendMessage();


	// Í¨¹ý NotificationProtocol ¼Ì³Ð
	virtual void notificationOnClickedSendButton(const QString& message) override;

protected slots:
	virtual void slotReadyRead();
	virtual void slotStateChanged(QAbstractSocket::SocketState socketState);

};
