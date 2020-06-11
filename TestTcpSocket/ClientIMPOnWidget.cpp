#include "ClientIMPOnWidget.h"

ClientIMPOnWidget::ClientIMPOnWidget(QWidget *parent)
	: QWidget(parent),
	ClientIMPProtocol()
{
	ui.setupUi(this);
	
	connect(ui.cBtnSend, &QPushButton::clicked, this, &ClientIMPOnWidget::onClickedBtnSend);
}

ClientIMPOnWidget::~ClientIMPOnWidget()
{
}

void ClientIMPOnWidget::showWidget(const QString& title)
{
	this->show();
	this->setWindowTitle(title);
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
