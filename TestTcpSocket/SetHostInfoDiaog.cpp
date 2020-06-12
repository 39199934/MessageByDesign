#include "SetHostInfoDiaog.h"

SetHostInfoDiaog::SetHostInfoDiaog(const QString& old_add, const quint16& old_port, QWidget *parent)
	: QDialog(parent),
	address(old_add),
	port(old_port)
{
	ui.setupUi(this);
	ui.cEditAddress->setText(old_add);
	ui.cEditPort->setText(QString::number(port));
	connect(ui.cBtnOK, &QPushButton::clicked, this, &SetHostInfoDiaog::onClickedOK);
	connect(ui.cBtnCancle, &QPushButton::clicked, this, &SetHostInfoDiaog::reject);

}

SetHostInfoDiaog::~SetHostInfoDiaog()
{
}

void SetHostInfoDiaog::onClickedOK()
{
	
	address = ui.cEditAddress->text();
	port =ui.cEditPort->text().toUInt();
	accept();
}

void SetHostInfoDiaog::onClickedCancle()
{
	exit(0);
}
