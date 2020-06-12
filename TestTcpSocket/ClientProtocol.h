#pragma once

#include <QObject>
#include <QTcpSocket>
#include "ClientIMPProtocol.h"
#include "ClientIMPOnWidget.h"
#include "NotificationProtocol.h"
#include <QWidget>
#include <QVBoxLayout>

class ClientProtocol : public QTcpSocket,public NotificationProtocol
{
	Q_OBJECT

public:
	ClientProtocol(QWidget* parent_widget);
	ClientProtocol(qintptr  socket_des, QWidget* parent_widget);
	virtual ~ClientProtocol();
	void connectToHost();
	//ClientIMPOnWidget* get
	void setWidgetTitle(const QString& title);
	void showWidget();

private:
	ClientIMPProtocol* imp = nullptr;
	ClientIMPOnWidget* wimp = nullptr;
	QWidget* parentWidget = nullptr;
	void slotOnClickedSendMessage();


	// ͨ�� NotificationProtocol �̳�
	virtual void notificationOnClickedSendButton(const QString& message) override;

protected slots:
	virtual void slotReadyRead();
	virtual void slotStateChanged(QAbstractSocket::SocketState socketState);



	// ͨ�� NotificationProtocol �̳�
	virtual void notificationOnClickedLinkButoon(QPushButton* linkBtn) override;

};
