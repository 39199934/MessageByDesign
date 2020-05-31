#include "MyClient.h"

MyClient::MyClient(QWidget *parent)
	: QWidget(parent),
	SocketIMPProtocol()
{
	ui.setupUi(this);
	//setWindowsItem(ui.cMessageHistory, ui.cMessageEdit, ui.cBtnSend);
	connect(ui.cBtnLink, &QPushButton::clicked, this, &MyClient::onClickedLink);
}

MyClient::~MyClient()
{
}

QByteArray MyClient::getNewMessage()
{
	auto result = ui.cMessageEdit->text().toLocal8Bit();
	ui.cMessageEdit->clear();
	return result;
}

void MyClient::viewMessage(const QByteArray& new_message)
{
	auto vmsg = QString::fromLocal8Bit(new_message);
	ui.cMessageHistory->append("new message:");
	ui.cMessageHistory->append(vmsg);
}

void MyClient::viewSocketState(QAbstractSocket::SocketState state)
{
	switch (state)
	{
	case QAbstractSocket::UnconnectedState:
		ui.cState->setText("unconnected");
		break;
	case QAbstractSocket::HostLookupState:
		ui.cState->setText("HostLookupState");
		break;
	case QAbstractSocket::ConnectingState:
		ui.cState->setText("ConnectingState");
		break;
	case QAbstractSocket::ConnectedState:
		ui.cState->setText("ConnectedState");
		break;
	case QAbstractSocket::BoundState:
		ui.cState->setText("BoundState");
		break;
	case QAbstractSocket::ListeningState:
		ui.cState->setText("ListeningState");
		break;
	case QAbstractSocket::ClosingState:
		ui.cState->setText("ClosingState");
		break;
	default:
		break;
	}
}

void MyClient::clearMessageHistory()
{
	ui.cMessageHistory->clear();
}

QString MyClient::getHostAddress()
{
	return "127.0.0.1";
}

qint16 MyClient::getHostPort()
{
	return 5666;
}

void MyClient::onClickedLink()
{
	//connectToHost("127.0.0.1", 5666);
}
