#include "ServerProtocol.h"

ServerProtocol::ServerProtocol(QObject *parent)
	: QTcpServer(parent),
	clients(new ClientsVectorProtocol())
{
	//connect(this, &ServerProtocol::newConnection, this, &ServerProtocol::slotOnNewClientComming);
}

ServerProtocol::~ServerProtocol()
{
	if (clients != nullptr) {
		delete clients;
		clients = nullptr;
	}
}

void ServerProtocol::incomingConnection(qintptr socketDescriptor)
{
	//ClientIMPOnWidget* widget = new ClientIMPOnWidget();
	ClientProtocol* client = new ClientProtocol(socketDescriptor, nullptr);
	//widget->setNotification(client);
	auto id = clients->append(client);
	client->setWidgetTitle("¿Í»§¶Ë´°¿Ú -" + id);
	//widget->showWidget();
}

void ServerProtocol::slotOnNewClientComming()
{
}
