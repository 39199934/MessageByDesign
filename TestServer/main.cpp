#include "TestServer.h"
#include <QtWidgets/QApplication>
#include "MyClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient w;
    w.show();
    return a.exec();
}
