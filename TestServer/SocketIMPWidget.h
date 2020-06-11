#pragma once

#include <QWidget>
#include "ui_SocketIMPWidget.h"
#include "ClientProtocol.h"
#include "SocketIMPProtocol.h"

class SocketIMPWidget : public QWidget,public SocketIMPProtocol
{
	Q_OBJECT

public:
	SocketIMPWidget(QWidget *parent = Q_NULLPTR);
	~SocketIMPWidget();

private:
	Ui::SocketIMPWidget ui;
	bool addressAndPortIsShow;
private slots:
	void onClickedLink();
public:
	// 通过 SocketIMPProtocol 继承
	virtual QByteArray getNewMessage() override;
	virtual void viewMessage(const QByteArray& new_message) override;
	virtual void viewSocketState(QAbstractSocket::SocketState state) override;
	virtual void clearMessageHistory() override;

	void hideAddressAndPort();
	void showAddressAndPort();

	// 通过 SocketIMPProtocol 继承
	virtual QString getHostAddress() override;
	virtual qint16 getHostPort() override;
};
