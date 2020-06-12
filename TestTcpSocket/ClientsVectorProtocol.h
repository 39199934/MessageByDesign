#pragma once
#include "ClientProtocol.h"
#include <QVector>
#include <QMap>
#include <QString>
#include <quuid.h>
class ClientsVectorProtocol
{
public:
	ClientsVectorProtocol();
	virtual ~ClientsVectorProtocol();

	void append(ClientProtocol* client, QString id );
	QString append(ClientProtocol* client);
	void remove(QString id);
	void remove(ClientProtocol* client);
	void replaceId(QString id, ClientProtocol* client);
	ClientProtocol* getClient(QString id);
	QVector<QString> getAllId();

protected:
	QMap<QString, ClientProtocol*> clients;

};

