#pragma once
#include <QString>
class NotificationProtocol
{
public:
	virtual ~NotificationProtocol();
	virtual void notificationOnClickedSendButton(const QString& message) = 0;
};

