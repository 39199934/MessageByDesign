#include "CryptoBodyProtocol.h"

CryptoBodyProtocol::CryptoBodyProtocol(BodyOfMessageProtocol* body_for_crypto, QObject* parent)
	: BodyOfMessageProtocol(parent),
	body(body_for_crypto)
{
	//BagProtocol::setOriginalByteArray(body->getBagByteArray());
	//setBagByteArray(body->getBagByteArray());
	bag = body->getBagByteArray();
	//this->setBagByteArray(body_for_crypto->getBagByteArray());

}


CryptoBodyProtocol::~CryptoBodyProtocol()
{
}

HeadOfMessage* CryptoBodyProtocol::buildHead()
{
	HeadOfMessage* head = new HeadOfMessage(this->parent());
	head->setBodySize(this->getBodySize());
	head->setBodyUuid(this->getQUuid());
	head->setCryptoType(this->getCryptoType());
	head->setType(body->getBodyType());

	return head;
}

QString CryptoBodyProtocol::getBodyType()
{
	return body->getBodyType();
}

void CryptoBodyProtocol::view(QTextBrowser* browser)
{
	auto b = getBagByteArray();
	auto b2 = getOriginalByteArray();
	browser->append(QString::fromLocal8Bit("加密消息:"));
	browser->append(QString::fromLocal8Bit("未加密数据:"));
	browser->append(QString::fromLocal8Bit(b));
	browser->append(QString::fromLocal8Bit("加密数据:"));
	browser->append(QString::fromLocal8Bit(b2));
	browser->append("\n\r");
}
/*
void CryptoBodyProtocol::setBagByteArray(const QByteArray& bytes)
{
	
	BagProtocol::setBagByteArray(bytes);
}
*/