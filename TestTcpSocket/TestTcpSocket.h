#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestTcpSocket.h"
#include "ClientIMPOnWidget.h"
#include "ClientProtocol.h"
#include "ServerProtocol.h"

class TestTcpSocket : public QMainWindow
{
	Q_OBJECT

public:
	TestTcpSocket(QWidget *parent = Q_NULLPTR);
	~TestTcpSocket();

private:
	Ui::TestTcpSocketClass ui;
	//ClientIMPProtocol* widget ;
	ClientProtocol *client;
	ServerProtocol* server;
};
