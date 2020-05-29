#include "IOWidget.h"
#include <QPushButton>
IOWidget::IOWidget(QWidget *parent)
	: QWidget(parent),
	IOProtocol(),
	btnSwitch(false)
{
	ui.setupUi(this);
	connect(ui.cBtn, &QPushButton::clicked, this, &IOWidget::onClickedBtn);
	this->show();
}

IOWidget::~IOWidget()
{
}

QByteArray IOWidget::input()
{
	text = ui.cInput->text().toLocal8Bit();
	ui.cInput->clear();
	return text;
}

void IOWidget::output()
{
	ui.cOutput->setText(QString::fromLocal8Bit(text));
}

void IOWidget::outputOrigin()
{
	ui.cOriginOutput->setText(QString::fromLocal8Bit(text));
}

void IOWidget::onClickedBtn()
{
	if (!btnSwitch) {
		input();
		ui.cBtn->setText("output");
	}
	else {
		output();
		outputOrigin();
		ui.cBtn->setText("input");
	}
	btnSwitch = !btnSwitch;

}
