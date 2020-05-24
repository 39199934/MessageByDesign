#include "BagProtocol.h"

BagProtocol::BagProtocol(QObject *parent)
	: QObject(parent),
	bag(QByteArray())
{
	QUuid uid = QUuid::createUuid();
	setQUuid(uid.toString());
}

BagProtocol::~BagProtocol()
{
}

QByteArray BagProtocol::getOriginalByteArray()
{
	
	return bag;
}

void BagProtocol::send(QTcpSocket* socket) {
	socket->write(getOriginalByteArray());
}
void BagProtocol::view(QTextBrowser* browser)
{
	auto b = getBagByteArray();
	browser->append(QString::fromLocal8Bit("包原始数据:\n"));
	browser->append(QString::fromLocal8Bit(b));
	browser->append("\n\r");
}
void BagProtocol::setOriginalByteArray(const QByteArray& bytes)
{
	bag = bytes;
	auto doc = getJsonFromBagByteArray();
	emit signalBagIsChanged(doc);
}

void BagProtocol::debugPrintByteArray()
{
	qDebug() << bag;
}

void BagProtocol::setBagByteArray(const QByteArray& bytes)
{
	setOriginalByteArray(bytes);
}

QByteArray BagProtocol::getBagByteArray()
{
	return getOriginalByteArray();
}

void BagProtocol::setBagByteArrayFromJson(const QJsonDocument& doc)
{
	auto bytes = doc.toJson();
	setBagByteArray(bytes);
}

QJsonDocument BagProtocol::getJsonFromBagByteArray()
{
	QJsonParseError error;
	auto b = getBagByteArray();
	if (b.isEmpty()) {
		return QJsonDocument();
	}
	QJsonDocument doc = QJsonDocument::fromJson(b, &error);
	if (error.error == QJsonParseError::ParseError::NoError) {
		return doc;
	}
	QJsonObject obj;
	obj.insert("error", error.errorString());
	
	QJsonDocument rtErrorDoc;
	rtErrorDoc.setObject(obj);
	return rtErrorDoc;
}

bool BagProtocol::insertJsonValue(QString key, QJsonValue value)
{
	auto doc = getJsonFromBagByteArray();
	auto obj = doc.object();
	obj.insert(key, value);
	doc.setObject(obj);
	setBagByteArrayFromJson(doc);
	return true;
}

QJsonValue BagProtocol::getJsonValue(const QString& key)
{
	auto doc = getJsonFromBagByteArray();
	auto obj = doc.object();
	return obj.value(key);
	
}

void BagProtocol::setQUuid(const QString& uuid)
{
	insertJsonValue("uuid", uuid);
}

QString BagProtocol::getQUuid()
{
	return getJsonValue("uuid").toString();
	
}
