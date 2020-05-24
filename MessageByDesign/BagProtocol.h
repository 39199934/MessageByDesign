#pragma once

#include <QObject>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUUID>
#include <QDebug>
#include <QTcpSocket>
#include <QThread>
#include <QTextBrowser>

class BagProtocol : public QObject
{
	Q_OBJECT

public:
	BagProtocol(QObject *parent=nullptr);
	virtual ~BagProtocol();

	QByteArray getOriginalByteArray();
	void send(QTcpSocket* socket);
	void debugPrintByteArray();
	virtual void view(QTextBrowser* browser);

	

public:
	virtual void setBagByteArray(const QByteArray&  bytes);
	virtual QByteArray getBagByteArray();
public:
	virtual void setBagByteArrayFromJson(const QJsonDocument& doc);
	virtual QJsonDocument getJsonFromBagByteArray();

	

protected:
	void setQUuid(const QString& uuid);
	void setOriginalByteArray(const QByteArray& bytes);
	QString getQUuid();


	virtual bool insertJsonValue(QString key, QJsonValue value);
	virtual QJsonValue getJsonValue(const QString& key);
protected:
	QByteArray bag;
signals:
	void signalBagIsChanged(QJsonDocument new_json);
};
