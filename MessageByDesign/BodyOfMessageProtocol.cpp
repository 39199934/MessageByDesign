#include "BodyOfMessageProtocol.h"

BodyOfMessageProtocol::BodyOfMessageProtocol(QObject *parent)
	: BagProtocol(parent)
{
}

BodyOfMessageProtocol::~BodyOfMessageProtocol()
{
}

QString BodyOfMessageProtocol::getCryptoType()
{
	return "noCrypto";
}

void BodyOfMessageProtocol::view(QTextBrowser* browser)
{
	auto b = getBagByteArray();
	browser->append(QString::fromLocal8Bit("消息体数据:"));
	browser->append(QString::fromLocal8Bit(b));
	browser->append("\n\r");
}

HeadOfMessage* BodyOfMessageProtocol::buildHead()
{
	HeadOfMessage* head = new HeadOfMessage(this->parent());
	head->setBodySize(this->getBodySize());
	head->setBodyUuid(this->getQUuid());
	head->setCryptoType(this->getCryptoType());
	head->setType(this->getBodyType());

	return head;
}

int BodyOfMessageProtocol::getBodySize()
{
	return getOriginalByteArray().size();
}
