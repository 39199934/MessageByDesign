#pragma once
#include <QString>
#include <QPushButton>
class NotificationProtocol
{
public:
	virtual ~NotificationProtocol();
	virtual void notificationOnClickedSendButton(const QString& message) = 0;
	virtual void notificationOnClickedLinkButoon(QPushButton * linkBtn) = 0;
};

