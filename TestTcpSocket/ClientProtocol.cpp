#include "ClientProtocol.h"

ClientProtocol::ClientProtocol(QWidget* parent_widget)
	: QTcpSocket(parent_widget),
	parentWidget(parent_widget)
{
	connect(this, &QTcpSocket::readyRead, this, &ClientProtocol::slotReadyRead);
	connect(this, &QTcpSocket::stateChanged, this, &ClientProtocol::slotStateChanged);
	wimp = new ClientIMPOnWidget();
	auto layout = parentWidget->layout();// new QVBoxLayout(parentWidget);//铺满布局
	
	
	wimp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);//铺满布局

	layout->addWidget(wimp);

	parentWidget->setLayout(layout);// ->horizontalLayoutChoose->addWidget(widget);
	imp = wimp;
	imp->setNotification(this);
}

ClientProtocol::ClientProtocol(qintptr socket_des, QWidget* parent_widget):
	ClientProtocol(parent_widget)
{
	setSocketDescriptor(socket_des);
}

ClientProtocol::~ClientProtocol()
{
	if (parentWidget != nullptr) {
		auto layout = parentWidget->layout();
		layout->removeWidget(wimp);
		//delete wimp;
		wimp = nullptr;
		
	}
	else {
		if ((imp != nullptr) && (true)) {

			delete imp;
			imp = nullptr;
		}
	}
}

void ClientProtocol::connectToHost()
{
	if (imp != nullptr) {
		QTcpSocket::connectToHost(imp->getHostAddress(), imp->getHostPort());
	}
}

void ClientProtocol::setWidgetTitle(const QString& title)
{
	imp->setWidgetTitle(title);
}

void ClientProtocol::showWidget()
{
	imp->showWidget();
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



void ClientProtocol::notificationOnClickedLinkButoon(QPushButton* linkBtn)
{
	if (imp != nullptr) {
		//QString viewState;
		auto address = imp->getHostAddress();
		auto port = imp->getHostPort();
		switch (this->state())
		{
		case QAbstractSocket::UnconnectedState:
		case QAbstractSocket::ClosingState:
			connectToHost();
			linkBtn->setText(QString::fromLocal8Bit("断开连接"));

			
			break;
		
		case QAbstractSocket::ConnectingState:
		case QAbstractSocket::ConnectedState:
			disconnectFromHost();
			//disconnect();
			linkBtn->setText(QString::fromLocal8Bit("连接"));
		
		
		default:
			
			break;
		}
		
	}
}
