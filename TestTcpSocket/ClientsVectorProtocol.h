#pragma once
#include "ClientProtocol.h"
#include <QVector>
#include <QMap>
#include <QString>
#include <quuid.h>
#include <QAbstractTableModel>
#include <QStandardItemModel>
class ClientsVectorProtocol: public QAbstractTableModel
{
public:
	ClientsVectorProtocol();
	virtual ~ClientsVectorProtocol();

	void append(ClientProtocol* client, QString id );
	QString append(ClientProtocol* client);
	void remove(QString id);
	void remove(ClientProtocol* client);
	void replaceId(QString id, ClientProtocol* client);
	ClientProtocol* getClient(QString id);
	ClientProtocol* getClient(const QModelIndex& index);
	QVector<QString> getAllId();

	void refrushModel();

protected:
	QMap<QString, ClientProtocol*> clients;
	/*

	// 通过 QAbstractItemModel 继承
	virtual Q_INVOKABLE QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;

	virtual Q_INVOKABLE QModelIndex parent(const QModelIndex& child) const override;

	virtual Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual Q_INVOKABLE int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual Q_INVOKABLE QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	*/
	// 通过 QAbstractTableModel 继承
	virtual Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual Q_INVOKABLE int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual Q_INVOKABLE QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	
};

