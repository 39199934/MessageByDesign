#include "CryptoBase64.h"

CryptoBase64::CryptoBase64(BodyOfMessageProtocol* body_for_crypto, QObject *parent)
	: CryptoBodyProtocol(body_for_crypto,parent)
{
	this->setBagByteArray(body_for_crypto->getBagByteArray());
}

CryptoBase64::~CryptoBase64()
{
}

void CryptoBase64::setBagByteArray(const QByteArray& bytes)
{
	auto base64 = bytes.toBase64();
	BagProtocol::setBagByteArray(base64);
}

QByteArray CryptoBase64::getBagByteArray()
{
	auto base64 = getOriginalByteArray();
	auto noBase = QByteArray::fromBase64(base64);
	return noBase;
}
/*
HeadOfMessage* CryptoBase64::buildHead()
{
	HeadOfMessage* head = new HeadOfMessage(this->parent());
	head->setBodySize(this->getBodySize());
	head->setBodyUuid(this->getQUuid());
	head->setCryptoType(this->getCryptoType());
	head->setType(body->getBodyType());

	return head;
}*/

QString CryptoBase64::getCryptoType()
{
	return "base64";
}
/*
QString CryptoBase64::getBodyType()
{
	return body->getBodyType();
}

void CryptoBase64::view(QTextBrowser* browser)
{
	auto b = getBagByteArray();
	auto b2 = getOriginalByteArray();
	browser->append(QString::fromLocal8Bit("加密消息:"));
	browser->append(QString::fromLocal8Bit("未加密数据:"));
	browser->append(QString::fromLocal8Bit(b));
	browser->append(QString::fromLocal8Bit("加密数据:"));
	browser->append(QString::fromLocal8Bit(b2));
	browser->append("\n\r");
}*/
