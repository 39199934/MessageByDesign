#pragma once

#include <QWidget>
#include "ui_MyClient.h"
#include "ClientProtocol.h"
#include "SocketIMPProtocol.h"

class MyClient : public QWidget,public SocketIMPProtocol
{
	Q_OBJECT

public:
	MyClient(QWidget *parent = Q_NULLPTR);
	~MyClient();

private:
	Ui::MyClient ui;
private slots:
	void onClickedLink();

	// ͨ�� SocketIMPProtocol �̳�
	virtual QByteArray getNewMessage() override;
	virtual void viewMessage(const QByteArray& new_message) override;
	virtual void viewSocketState(QAbstractSocket::SocketState state) override;
	virtual void clearMessageHistory() override;

	// ͨ�� SocketIMPProtocol �̳�
	virtual QString getHostAddress() override;
	virtual qint16 getHostPort() override;
};
