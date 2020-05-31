#include "ClientProtocol.h"

ClientProtocol::ClientProtocol(QObject *parent)
	: QObject(parent),
	socket(nullptr),
	cMessageEdit(nullptr),
	cMessageHistory(nullptr),
	cBtnSend(nullptr)
{
	
}

ClientProtocol::~ClientProtocol()
{
}

void ClientProtocol::connectToHost(const QString& address, const qint16& port)
{
	QTcpSocket* sock = new QTcpSocket(this);
	auto addr = QHostAddress(address);
	sock->connectToHost(addr, port);
	setTcpSocket(socket);
}

void ClientProtocol::disConnectToHost()
{
	socket->disconnect();
}

void ClientProtocol::slotSocketIsConnected()
{
	cMessageHistory->append("socket is connected");
}

void ClientProtocol::setWindowsItem(QTextBrowser* message_history, QLineEdit* message_edit, QPushButton* button_send)
{
	cMessageEdit = message_edit;
	cMessageHistory = message_history;
	if (button_send) {
		cBtnSend = button_send;
		connect(cBtnSend, &QPushButton::clicked, this, &ClientProtocol::onClickedSendButton);
	}
}

QTextBrowser* ClientProtocol::getMessageHistory()
{
	return cMessageHistory;
}

QLineEdit* ClientProtocol::getMessageEdit()
{
	return cMessageEdit;
}

QPushButton* ClientProtocol::getButtonForSend()
{
	return cBtnSend;
}

void ClientProtocol::setTcpSocket(QTcpSocket* new_socket)
{
	if (socket != nullptr) {
		delete socket;
		socket = nullptr;
	}
	socket = new_socket;
	connect(socket, &QTcpSocket::connected, this, &ClientProtocol::slotSocketIsConnected);
	connect(socket, &QTcpSocket::stateChanged, this, &ClientProtocol::slotSocketStateChanged);
}

QTcpSocket* ClientProtocol::getTcpSocket()
{
	return socket;
}

void ClientProtocol::onClickedSendButton()
{
	if (socket == nullptr) {
		return;
	}
	socket->write(cMessageEdit->text().toLocal8Bit());
	cMessageEdit->clear();
}

void ClientProtocol::slotSocketStateChanged(QAbstractSocket::SocketState state)
{
	cMessageHistory->append("socket state is changed," + state);
}
