#include "IOStd.h"

QString IOStd::input()
{
	cout << "Please input:";
	char* str = new char[120]();
	cin >> str;
	QByteArray by = QByteArray::fromRawData(str, strlen(str));
	text = QString::fromLocal8Bit(by);
	delete[] str;
	return text;
}

void IOStd::output()
{
	cout << "the text = " << text.toLocal8Bit().toStdString()<<endl;
}

void IOStd::outputOrigin()
{
	cout << "the origin text = " << text.toLocal8Bit().toStdString() << endl;
}
