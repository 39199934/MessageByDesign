#pragma once

#include <QObject>
#include <QWidget>
#include <QTextBrowser>
#include <QLineEdit>
#include <QPushButton>
//#include <QNetWork>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>


class ClientProtocol: public QObject
{
	Q_OBJECT

public:
	ClientProtocol(QObject *parent = Q_NULLPTR);
	virtual ~ClientProtocol();

public:
	void connectToHost(const QString& address, const qint16& port);
	void disConnectToHost();

	

protected:
	void setWindowsItem(QTextBrowser* message_history, QLineEdit* message_edit, QPushButton* button_send = nullptr);
	QTextBrowser* getMessageHistory();
	QLineEdit* getMessageEdit();
	QPushButton* getButtonForSend();


	void setTcpSocket(QTcpSocket* socket);
	QTcpSocket* getTcpSocket();

protected:
	QTextBrowser* cMessageHistory;
	QLineEdit* cMessageEdit;
	QPushButton* cBtnSend;
	QTcpSocket* socket;


protected slots:
	virtual void slotSocketIsConnected();
	virtual void onClickedSendButton();
	virtual void slotSocketStateChanged(QAbstractSocket::SocketState state);

	
};
