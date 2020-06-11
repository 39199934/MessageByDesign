#include "SocketIMPStd.h"

QByteArray SocketIMPStd::getNewMessage()
{
	cout << "Please input new message:";
	string msg;
	cin >> msg;
	auto bytes = QByteArray(msg.c_str(), msg.size());
	return bytes;
}

void SocketIMPStd::viewMessage(const QByteArray& new_message)
{
	char* p = new char[new_message.size()]();
	auto bp = new_message.data();
	auto len = strlen(bp);
	memcpy_s(p, len, bp, len);
	p[len] = '\0';
	cout << "new message:" << p << endl;;
}

void SocketIMPStd::viewSocketState(QAbstractSocket::SocketState state)
{
	cout << "connect state is changed" << endl;
}

void SocketIMPStd::clearMessageHistory()
{
	cout.clear();
}

QString SocketIMPStd::getHostAddress()
{
	return "127.0.0.1";
}

qint16 SocketIMPStd::getHostPort()
{
	return 5666;
}
