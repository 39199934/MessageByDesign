#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestServer.h"

class TestServer : public QMainWindow
{
    Q_OBJECT

public:
    TestServer(QWidget *parent = Q_NULLPTR);

private:
    Ui::TestServerClass ui;
};
