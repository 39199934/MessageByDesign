#include "ClientsVectorProtocol.h"

ClientsVectorProtocol::ClientsVectorProtocol():
	clients(QMap<QString,ClientProtocol*>())
{
}

ClientsVectorProtocol::~ClientsVectorProtocol()
{
	for (auto i = clients.begin(); i != clients.end(); i++) {
		if (i.value() != nullptr) {
			delete i.value();
			i.value() = nullptr;
			clients.remove(i.key());
		}
	}
}

void ClientsVectorProtocol::append(ClientProtocol* client, QString id)
{
	if (!clients.keys().contains(id))
	{
		clients.insert(id, client);
	}
	else {
		remove(id);
		clients.insert(id, client);
	}
}

QString ClientsVectorProtocol::append(ClientProtocol* client)
{
	bool isHave = false;
	for (auto i = clients.begin(); i != clients.end(); i++) {
		if (i.value() == client) {
			
			return i.key();
		}
	}
	QString id = QUuid::createUuid().toString();
	append(client, id);
	return id;
}

void ClientsVectorProtocol::remove(QString id)
{
	if (clients.keys().contains(id))
	{

		delete  clients[id];
		clients[id] = nullptr;
		clients.remove(id);
	}
}

void ClientsVectorProtocol::remove(ClientProtocol* client)
{
	for (auto i = clients.begin(); i != clients.end(); i++) {
		if (i.value() != client) {
			clients.remove(i.key());
		}
	}
}

void ClientsVectorProtocol::replaceId(QString id, ClientProtocol* client)
{
	if (!clients.keys().contains(id))
	{
		//clients.insert(id, client);
	}
	else {
		remove(id);
		append(client, id);
		//clients.insert(id, client);
	}
}

ClientProtocol* ClientsVectorProtocol::getClient(QString id)
{
	return clients[id];
}

QVector<QString> ClientsVectorProtocol::getAllId()
{
	QVector<QString> ids;
	for (auto i = clients.begin(); i != clients.end(); i++) {
		ids.append(i.key());
	}
	return ids;

}
