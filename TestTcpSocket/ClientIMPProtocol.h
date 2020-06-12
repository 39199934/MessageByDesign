#pragma once

#include <QObject>
#include <QByteArray>
#include "NotificationProtocol.h"

class ClientIMPProtocol
{
	

public:
	ClientIMPProtocol();
	virtual ~ClientIMPProtocol();
public:
	virtual void setConnectState(const QString& state) = 0;
	virtual void appendMessageHistory(const QByteArray& bytes) = 0;
	virtual QString getMessageForSend() = 0;
	virtual void onClickedBtnSend() = 0;
	QString getHostAddress();
	quint16 getHostPort();

	void setNotification(NotificationProtocol* new_notification);
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("客户端窗口")) =0;
	virtual void setWidgetTitle(const QString& title = QString::fromLocal8Bit("客户端窗口")) = 0;
	NotificationProtocol* getNotification();
protected:
	NotificationProtocol* notification;
	QString hostAddress;
	quint16 hostPort;

};
