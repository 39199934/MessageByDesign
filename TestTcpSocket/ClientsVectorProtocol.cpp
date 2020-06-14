#include "ClientsVectorProtocol.h"

ClientsVectorProtocol::ClientsVectorProtocol():
	clients(QMap<QString,ClientProtocol*>())
{
}

ClientsVectorProtocol::~ClientsVectorProtocol()
{
	for (auto i = clients.begin(); i != clients.end(); ) {
		auto key = i.key();
		i++;
		auto client = clients.take(key);

		if (client != nullptr) {
			
			client->deleteLater();
			//delete client;
			//client = nullptr;
			//i.value() = nullptr;
			//clients.remove(i.key());
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
	refrushModel();
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
	refrushModel();
}

void ClientsVectorProtocol::remove(ClientProtocol* client)
{
	for (auto i = clients.begin(); i != clients.end(); i++) {
		if (i.value() != client) {
			clients.remove(i.key());
		}
	}
	refrushModel();
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
	refrushModel();
}

ClientProtocol* ClientsVectorProtocol::getClient(QString id)
{
	return clients[id];
}

ClientProtocol* ClientsVectorProtocol::getClient(const QModelIndex& index)
{
	auto str = data(index, Qt::DisplayRole).toString();
	return getClient(str);
}

QVector<QString> ClientsVectorProtocol::getAllId()
{
	QVector<QString> ids;
	for (auto i = clients.begin(); i != clients.end(); i++) {
		ids.append(i.key());
	}
	return ids;

}
void ClientsVectorProtocol::refrushModel()
{
	
	beginResetModel();
	endResetModel();
	emit dataChanged(QModelIndex(), QModelIndex());
	//emit updateCount(this->rowCount(QModelIndex()));
}
/*
Q_INVOKABLE QModelIndex ClientsVectorProtocol::index(int row, int column, const QModelIndex& parent = QModelIndex()) const
{
	return Q_INVOKABLE QModelIndex();
}
Q_INVOKABLE QModelIndex ClientsVectorProtocol::parent(const QModelIndex& child) const
{
	return Q_INVOKABLE QModelIndex();
}
Q_INVOKABLE int ClientsVectorProtocol::rowCount(const QModelIndex& parent = QModelIndex()) const
{
	return Q_INVOKABLE int();
}
Q_INVOKABLE int ClientsVectorProtocol::columnCount(const QModelIndex& parent = QModelIndex()) const
{
	return Q_INVOKABLE int();
}
Q_INVOKABLE QVariant ClientsVectorProtocol::data(const QModelIndex& index, int role = Qt::DisplayRole) const
{
	return Q_INVOKABLE QVariant();
}
*/
Q_INVOKABLE int ClientsVectorProtocol::rowCount(const QModelIndex& parent ) const
{
	//return 10;
	return clients.count();
}

Q_INVOKABLE int ClientsVectorProtocol::columnCount(const QModelIndex& parent ) const
{
	return 1;
}

Q_INVOKABLE QVariant ClientsVectorProtocol::data(const QModelIndex& index, int role) const
{
	QVector<QString> ids;
	for (auto i = clients.begin(); i != clients.end(); i++) {
		ids.append(i.key());
	}
	if (index.column() == 0) {
		if (role == Qt::DisplayRole) {
			//return "ddddddd";
			return ids[index.row()];
		}
	}
	return QVariant();
}
