#include "TestServer.h"
#include <QtWidgets/QApplication>
#include "SocketIMPWidget.h"
#include "SocketIMPStd.h"
#include "MySocket.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestServer w;
    //MySocket socket(new SocketIMPStd());
    //socket.linkToHost();
    //socket.sendMessage();
    
    w.show();
    return a.exec();
}
