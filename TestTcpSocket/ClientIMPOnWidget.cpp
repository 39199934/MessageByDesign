#include "ClientIMPOnWidget.h"

ClientIMPOnWidget::ClientIMPOnWidget(QWidget *parent)
	: QWidget(parent),
	ClientIMPProtocol()
{
	ui.setupUi(this);
	
	connect(ui.cBtnSend, &QPushButton::clicked, this, &ClientIMPOnWidget::onClickedBtnSend);
	connect(ui.cBtnLink, &QPushButton::clicked, this, &ClientIMPOnWidget::onClickedBtnLink);
	connect(ui.cBtnSetHost, &QPushButton::clicked, this, &ClientIMPOnWidget::onClickedSetHost);
}

ClientIMPOnWidget::~ClientIMPOnWidget()
{
	this->close();
}

void ClientIMPOnWidget::showWidget(const QString& title)
{
	this->show();
	this->setWindowTitle(title);
}

void ClientIMPOnWidget::onClickedBtnLink()
{
	if (notification != nullptr) {
		notification->notificationOnClickedLinkButoon(ui.cBtnLink);
	}
}

void ClientIMPOnWidget::onClickedSetHost()
{
	SetHostInfoDiaog dia(hostAddress, hostPort, this);
	dia.exec();
	hostAddress = dia.address;
	hostPort = dia.port;
	
}

void ClientIMPOnWidget::setWidgetTitle(const QString& title )
{
	this->setWindowTitle(title);
	this->update();
}

void ClientIMPOnWidget::onClickedBtnSend()
{
	if (notification != nullptr) {
		notification->notificationOnClickedSendButton(getMessageForSend());
	}
	
}

void ClientIMPOnWidget::setConnectState(const QString& state)
{
	ui.cConnectState->setText(state);
}

void ClientIMPOnWidget::appendMessageHistory(const QByteArray& bytes)
{
	ui.cMsgHistory->append(QString::fromLocal8Bit(bytes));
}

QString ClientIMPOnWidget::getMessageForSend()
{
	auto msg =  ui.cMsgForSend->text();
	ui.cMsgForSend->clear();
	return msg;
}
