#include "SocketIMPWidget.h"

SocketIMPWidget::SocketIMPWidget(QWidget *parent)
	: QWidget(parent),
	SocketIMPProtocol(),
	addressAndPortIsShow(true)
{
	ui.setupUi(this);
	
	//setWindowsItem(ui.cMessageHistory, ui.cMessageEdit, ui.cBtnSend);
	//connect(ui.cBtnLink, &QPushButton::clicked, this, &SocketIMPWidget::onClickedLink);
	ui.cAddressEdit->setText("127.0.0.1");
	ui.cPortEdit->setText("5666");
	hideAddressAndPort();
}

SocketIMPWidget::~SocketIMPWidget()
{
}

QByteArray SocketIMPWidget::getNewMessage()
{
	auto result = ui.cMessageEdit->text().toLocal8Bit();
	ui.cMessageEdit->clear();
	return result;
}

void SocketIMPWidget::viewMessage(const QByteArray& new_message)
{
	auto vmsg = QString::fromLocal8Bit(new_message);
	ui.cMessageHistory->append("new message:");
	ui.cMessageHistory->append(vmsg);
}

void SocketIMPWidget::viewSocketState(QAbstractSocket::SocketState state)
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

void SocketIMPWidget::clearMessageHistory()
{
	ui.cMessageHistory->clear();
}

void SocketIMPWidget::hideAddressAndPort()
{
	addressAndPortIsShow = false;
	ui.cAddressEdit->setHidden(true);
	ui.cPortEdit->setHidden(true);
}

void SocketIMPWidget::showAddressAndPort()
{
	addressAndPortIsShow = true;
	ui.cAddressEdit->setHidden(false);
	ui.cPortEdit->setHidden(false);
}

QString SocketIMPWidget::getHostAddress()
{
	return ui.cAddressEdit->text();
}

qint16 SocketIMPWidget::getHostPort()
{
	QString p = ui.cPortEdit->text();
	return p.toInt();
	//return 5666;
}

void SocketIMPWidget::onClickedLink()
{
	//connectToHost("127.0.0.1", 5666);
}
