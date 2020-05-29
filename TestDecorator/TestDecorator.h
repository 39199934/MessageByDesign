#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestDecorator.h"
#include "IOStd.h"
#include "IOWidget.h"
#include "IOProtocolDecorator.h"
#include "IOProtocolDecoratorCrypto.h"
#include <QComboBox>

class TestDecorator : public QMainWindow
{
	Q_OBJECT

public:
	TestDecorator(QWidget *parent = Q_NULLPTR);
	~TestDecorator();
public slots:

	void onClickedInput();
	void onClickedOutput();
	void onClickedOutputOrigin();
	void onClickedStdIO();
	void onClickedWidgetIO();
	void onChangedComboBox(int index);

private:
	Ui::TestDecoratorClass ui;
	IOProtocol* io;
	IOProtocol* wid;
	IOProtocol* buildIOProtocol();
};
