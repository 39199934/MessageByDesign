#include "ClientProtocol.h"

ClientProtocol::ClientProtocol(ClientIMPProtocol* new_imp, QObject *parent)
	: QTcpSocket(parent),
	imp(new_imp)
{
	connect(this, &QTcpSocket::readyRead, this, &ClientProtocol::slotReadyRead);
	connect(this, &QTcpSocket::stateChanged, this, &ClientProtocol::slotStateChanged);
}

ClientProtocol::ClientProtocol(qintptr socket_des, ClientIMPProtocol* new_imp, QObject* parent):
	ClientProtocol(new_imp,parent)
{
	setSocketDescriptor(socket_des);
}

ClientProtocol::~ClientProtocol()
{
	if (imp != nullptr) {
		delete imp;
	}
}

void ClientProtocol::connectToHost()
{
	if (imp != nullptr) {
		QTcpSocket::connectToHost(imp->getHostAddress(), imp->getHostPort());
	}
}

void ClientProtocol::slotOnClickedSendMessage()
{
	if (imp != nullptr) {
		QString msg = imp->getMessageForSend();
		write(msg.toLocal8Bit());
	}
}

void ClientProtocol::notificationOnClickedSendButton(const QString& message)
{
	write(message.toLocal8Bit());
	if (imp != nullptr) {
		imp->appendMessageHistory("send:\r\n"+ message.toLocal8Bit());
	}
}

void ClientProtocol::slotReadyRead()
{
	auto bytes = readAll();
	if (imp != nullptr) {
		imp->appendMessageHistory("recive:\r\n" + bytes);
	}
}

void ClientProtocol::slotStateChanged(QAbstractSocket::SocketState socketState)
{
	if (imp != nullptr) {
		QString viewState;
		switch (socketState)
		{
		case QAbstractSocket::UnconnectedState:
			viewState = "UnconnectedState";
			break;
		case QAbstractSocket::HostLookupState:
			viewState = "HostLookupState";
			break;
		case QAbstractSocket::ConnectingState:
			viewState = "ConnectingState";
			break;
		case QAbstractSocket::ConnectedState:
			viewState = "ConnectedState";
			break;
		case QAbstractSocket::BoundState:
			viewState = "BoundState";
			break;
		case QAbstractSocket::ListeningState:
			viewState = "ListeningState";
			break;
		case QAbstractSocket::ClosingState:
			viewState = "ClosingState";
			break;
		default:
			viewState = "default";
			break;
		}
		imp->setConnectState(viewState);
	}
}
