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

QString IOWidget::input()
{
	text = ui.cInput->text();
	ui.cInput->clear();
	return text;
}

void IOWidget::output()
{
	ui.cOutput->setText(text);
}

void IOWidget::outputOrigin()
{
	ui.cOriginOutput->setText(text);
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
