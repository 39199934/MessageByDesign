#include "ClientIMPOnStd.h"

void ClientIMPOnStd::setConnectState(const QString& state)
{
	cout <<"state is changed:"<< state.toStdString() << endl;
}

void ClientIMPOnStd::appendMessageHistory(const QByteArray& bytes)
{
	cout << "new message:" << bytes.toStdString() << endl;
}

QString ClientIMPOnStd::getMessageForSend()
{
	cout << "Please input msg:";
	string str;
	cin >> str;
	return QString(str.c_str());
}

void ClientIMPOnStd::onClickedBtnSend()
{
}

void ClientIMPOnStd::showWidget(const QString& title )
{
	cout << "show widget,title = " << title.toStdString() << endl;
}
