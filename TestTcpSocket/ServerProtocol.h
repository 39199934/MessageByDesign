#pragma once

#include <QtNetwork/QTcpServer>
#include "ClientProtocol.h"
#include "ClientsVectorProtocol.h"
#include "ServerIMPWidget.h"
#include "qabstractitemmodel.h"
#include <QAbstractTableModel>


class ServerProtocol : public QTcpServer
{
	Q_OBJECT

public:
	ServerProtocol(QObject *parent);
	~ServerProtocol();
protected:
	ClientsVectorProtocol* clients;
	virtual void	incomingConnection(qintptr socketDescriptor) override;
	virtual void slotOnNewClientComming();

private:
	ServerIMPWidget* imp;
private slots:
	void slotClientsListClicked(const QModelIndex& index);


	

};
