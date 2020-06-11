#include "TestServer.h"

TestServer::TestServer(QWidget* parent)
    : QMainWindow(parent),
    isLink(false),
    server(new MyServer(this))
{
    ui.setupUi(this);
    
  //  socket = new MySocket(new SocketIMPWidget(ui.cWidget), parent);
    connect(ui.cBtnSend, &QPushButton::clicked, this, &TestServer::onClickedSend);
    connect(ui.cBtnLink, &QPushButton::clicked, this, &TestServer::onClickedLink);
    


}

void TestServer::onClickedSend()
{
    socket->sendMessage();
    
}

void TestServer::onClickedLink()
{
    if (!isLink) {
        socket->linkToHost();
        ui.cBtnLink->setText("disconnect");
    }
    else {
        socket->disconnect();
        ui.cBtnLink->setText("link");
    }
    isLink = !isLink;
}
