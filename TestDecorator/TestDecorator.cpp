#include "TestDecorator.h"

TestDecorator::TestDecorator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//wid = new IOWidget(nullptr);
	wid = new IOStd();
	io = new IOProtocolDecoratorCrypto(wid);
	//connect()
	connect(ui.cInput, &QPushButton::clicked, this, &TestDecorator::onClickedInput);
	connect(ui.cOutput, &QPushButton::clicked, this, &TestDecorator::onClickedOutput);
	connect(ui.cOutputOrigin, &QPushButton::clicked, this, &TestDecorator::onClickedOutputOrigin);
	connect(ui.cStd, &QPushButton::clicked, this, &TestDecorator::onClickedStdIO);
	connect(ui.cWidget, &QPushButton::clicked, this, &TestDecorator::onClickedWidgetIO);
}

void TestDecorator::onClickedInput()
{
	io->input();
}

TestDecorator::~TestDecorator()
{
	if (wid != nullptr) {
		delete wid;
	}
	if (io != nullptr) {
		delete io;
	}
}

void TestDecorator::onClickedOutput()
{
	io->output();
}

void TestDecorator::onClickedOutputOrigin()
{
	io->outputOrigin();
}

void TestDecorator::onClickedStdIO()
{
	if (io != nullptr) {
		delete io;
		io = nullptr;
	}
	if (wid != nullptr) {
		delete wid;
		wid = nullptr;
	}
	wid = new IOStd();
	io = new IOProtocolDecoratorCrypto(wid);
}

void TestDecorator::onClickedWidgetIO()
{
	if (io != nullptr) {
		delete io;
		io = nullptr;
	}
	if (wid != nullptr) {
		delete wid;
		wid = nullptr;
	}
	
	wid = new IOWidget();
	io = new IOProtocolDecoratorCrypto(wid);
}
