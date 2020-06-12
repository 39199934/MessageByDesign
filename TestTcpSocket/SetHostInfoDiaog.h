#pragma once

#include <QDialog>
#include "ui_SetHostInfoDiaog.h"
#include <QPushButton>

class SetHostInfoDiaog : public QDialog
{
	Q_OBJECT

public:
	SetHostInfoDiaog(const QString& old_add,const quint16& old_port, QWidget *parent = Q_NULLPTR);
	~SetHostInfoDiaog();
	QString address;
	quint16 port;

private:
	Ui::SetHostInfoDiaog ui;
	void onClickedOK();
	void onClickedCancle();
};
