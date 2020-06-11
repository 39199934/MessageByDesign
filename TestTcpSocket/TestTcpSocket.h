#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestTcpSocket.h"

class TestTcpSocket : public QMainWindow
{
	Q_OBJECT

public:
	TestTcpSocket(QWidget *parent = Q_NULLPTR);

private:
	Ui::TestTcpSocketClass ui;
};
