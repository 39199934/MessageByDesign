#include "HeadOfMessage.h"

HeadOfMessage::HeadOfMessage(QObject *parent)
	: BagProtocol(parent)
{
}

HeadOfMessage::~HeadOfMessage()
{
}

void HeadOfMessage::setType(const QString& type)
{
	insertJsonValue("msgType", type);
}

QString HeadOfMessage::getType()
{
	return getJsonValue("msgType").toString();
}

void HeadOfMessage::setCryptoType(const QString& crypto_type)
{
	insertJsonValue("cryptoType", crypto_type);
}

QString HeadOfMessage::getCryptoType()
{
	return getJsonValue("cryptoType").toString();
}

void HeadOfMessage::setBodyUuid(const QString& body_uuid)
{
	insertJsonValue("bodyUuid", body_uuid);
}

QString HeadOfMessage::getBodyUuid()
{
	return getJsonValue("bodyUuid").toString();
}

void HeadOfMessage::setBodySize(int body_size)
{
	insertJsonValue("bodySize", body_size);
}

int HeadOfMessage::getBodySize()
{
	return getJsonValue("bodySize").toInt();
}

void HeadOfMessage::view(QTextBrowser* browser)
{
	auto b = getBagByteArray();
	browser->append(QString::fromLocal8Bit("消息头数据:"));
	browser->append(QString::fromLocal8Bit(b));
	browser->append("\n\r");
}
