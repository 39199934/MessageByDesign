#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestServer.h"
#include "MySocket.h"
#include "SocketIMPWidget.h"
#include "MyServer.h"
class TestServer : public QMainWindow
{
    Q_OBJECT

public:
    TestServer(QWidget *parent = Q_NULLPTR);
    MySocket* socket;
    MyServer* server;

private:
    Ui::TestServerClass ui;
    bool isLink;
private slots:
    void onClickedSend();
    void onClickedLink();
    

};
