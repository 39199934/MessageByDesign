#include "MessageByDesign.h"
#include <QtWidgets/QApplication>
#include "BagProtocol.h"
#include "MyCryptoProtocol.h"
#include "MyCryptoBuilder.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MessageByDesign w;
	QByteArray bytes("hello ,world÷–");
	MyCryptoBuilder cry(MyCryptoProtocol::simple);

	auto cryStr = cry.encoder( bytes);
	auto deStr = cry.decoder( cryStr);
	qDebug() << "origin:" << bytes;
	qDebug() << "cryted:" << cryStr;
	qDebug() << "decode:" << deStr;
	//BagProtocol bag;
	//bag.debugPrintByteArray();
	w.show();
	return a.exec();
}
