#include "ServerProtocol.h"

ServerProtocol::ServerProtocol(QObject* parent)
	: QTcpServer(parent),
	clients(new ClientsVectorProtocol()),
	imp(new ServerIMPWidget())
{
	imp->setClienstListModel(clients);
	connect(imp, &ServerIMPWidget::signalClientsListClicked, this, &ServerProtocol::slotClientsListClicked);
	//connect(this, &ServerProtocol::newConnection, this, &ServerProtocol::slotOnNewClientComming);
	imp->show();
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
	//client->setWidgetTitle( id);.get
	imp->addClientWidget(client->getWidgetImp());
	//client->showWidget(id);
	//widget->showWidget();
	imp->refreshClientsList();
}

void ServerProtocol::slotOnNewClientComming()
{
}

void ServerProtocol::slotClientsListClicked(const QModelIndex& index)
{
	ClientProtocol* client = clients->getClient(index);
	//widget->setNotification(client);
	
	//client->setWidgetTitle( id);.get
	if (client != nullptr) {
		imp->addClientWidget(client->getWidgetImp());
	}
	//client->showWidget(id);
	//widget->showWidget();
	

}
