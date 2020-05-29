#pragma once

#include <QWidget>
#include "ui_IOWidget.h"
#include "IOProtocol.h"

class IOWidget : public QWidget, public IOProtocol
{
	Q_OBJECT

public:
	IOWidget(QWidget *parent = Q_NULLPTR);
	~IOWidget();

	virtual QByteArray input() override;
	virtual void output() override;
	virtual void outputOrigin();
public slots:
	void onClickedBtn();
public:
	Ui::IOWidget ui;
	bool btnSwitch;
};
