#include "IOStd.h"

QByteArray IOStd::input()
{
	cout << "Please input:";
	char* str = new char[120]();
	cin >> str;
	QByteArray by = QByteArray(str);
	text = by;
	delete[] str;
	return text;
}

void IOStd::output()
{
	cout << "the text = " << text.constData()<<endl;
}

void IOStd::outputOrigin()
{
	cout << "the origin text = " << text.constData() << endl;
}
