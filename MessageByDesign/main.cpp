#include "MessageByDesign.h"
#include <QtWidgets/QApplication>
#include "BagProtocol.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MessageByDesign w;

	BagProtocol bag;
	bag.debugPrintByteArray();
	w.show();
	return a.exec();
}
