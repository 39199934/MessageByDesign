#pragma once

#include <QTcpServer>
#include "ClientProtocol.h"
#include "ClientsVectorProtocol.h"

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

};
