#pragma once

#include <QtWidgets/QWidget>//< QWidget>
#include "ui_ServerIMPWidget.h"
#include "ClientIMPOnWidget.h"
#include <QVBoxLayout>
#include <qabstractitemmodel.h>
#include <QModelIndex>

class ServerIMPWidget : public QWidget
{
	Q_OBJECT

public:
	ServerIMPWidget(QWidget *parent = Q_NULLPTR);
	~ServerIMPWidget();

	void addClientWidget(QWidget* clientWidget);
	virtual void  setClienstListModel(QAbstractItemModel* model);
	void refreshClientsList();

private:
	Ui::ServerIMPWidget ui;
	QWidget* currentWidget;
private slots:
	void slotClientsListClicked(const QModelIndex& index);
signals:
	void signalClientsListClicked(const QModelIndex& index);
	
};
