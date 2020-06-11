#include "ClientIMPProtocol.h"

ClientIMPProtocol::ClientIMPProtocol() :
	notification(nullptr),
	hostAddress("127.0.0.1"),
	hostPort(5666)
{
}

ClientIMPProtocol::~ClientIMPProtocol()
{
}

QString ClientIMPProtocol::getHostAddress()
{
	return hostAddress;
}

quint16 ClientIMPProtocol::getHostPort()
{
	return hostPort;
}

void ClientIMPProtocol::setNotification(NotificationProtocol* new_notification)
{
	notification = new_notification;
}

NotificationProtocol* ClientIMPProtocol::getNotification()
{
	return notification;
}

