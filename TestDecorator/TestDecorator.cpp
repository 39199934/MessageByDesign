#include "TestDecorator.h"

TestDecorator::TestDecorator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//wid = new IOWidget(nullptr);
	wid = new IOStd();
	io = new IOProtocolDecoratorCrypto(wid,new MySimpleCrypto());
	//connect()
	connect(ui.cInput, &QPushButton::clicked, this, &TestDecorator::onClickedInput);
	connect(ui.cOutput, &QPushButton::clicked, this, &TestDecorator::onClickedOutput);
	connect(ui.cOutputOrigin, &QPushButton::clicked, this, &TestDecorator::onClickedOutputOrigin);
	connect(ui.cStd, &QPushButton::clicked, this, &TestDecorator::onClickedStdIO);
	connect(ui.cWidget, &QPushButton::clicked, this, &TestDecorator::onClickedWidgetIO);
	connect(ui.cComboBox,SIGNAL(currentIndexChanged(int)), this, SLOT(onChangedComboBox(int)));
	ui.cComboBox->setEditable(false);
	ui.cKey->setEnabled(false);
}

void TestDecorator::onClickedInput()
{
	buildIOProtocol();
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
	/*
	if (wid != nullptr) {
		delete wid;
		wid = nullptr;
	}
	wid = new IOStd();
	buildIOProtocol();
	*/
	}

void TestDecorator::onClickedWidgetIO()

{
	/*
	if (io != nullptr) {
		delete io;
		io = nullptr;
	}
	if (wid != nullptr) {
		delete wid;
		wid = nullptr;
	}
	
	wid = new IOWidget();
	
	buildIOProtocol();
	*/
}

void TestDecorator::onChangedComboBox(int index)
{
	if (index == 4) {
		ui.cKey->setEnabled(true);
	}
	else {
		ui.cKey->setEnabled(false);
	}
}

IOProtocol* TestDecorator::buildIOProtocol()
{
	if (io != nullptr) {
		delete io;
		io = nullptr;
	}
	if (wid != nullptr) {
		delete wid;
		wid = nullptr;
	}
	QByteArray key = "lodestar";
	switch (ui.cIOType->currentIndex())
	{
	case 0:
		wid = new IOStd();// (wid, new MySimpleCrypto());
		break;
	case 1:
		wid = new IOWidget(nullptr);// (wid, new MyMoveCrypto());
		break;
	case 2:
		wid = new IOFile();// (wid, new MyMoveLowerCrypto());
		break;
	case 3:
		wid = new IOStd();
		break;
	default:
		wid = new IOStd();
		break;
	}
	switch (ui.cComboBox->currentIndex())
	{
	case 0:
		io = new IOProtocolDecoratorCrypto(wid,new MySimpleCrypto());
		break;
	case 1:
		io = new IOProtocolDecoratorCrypto(wid, new MyMoveCrypto());
		break;
	case 2:
		io = new IOProtocolDecoratorCrypto(wid, new MyMoveLowerCrypto());
		break;
	case 3:
		io = new IOProtocolDecoratorCrypto(wid, new MyMoveTextCrypto());
		break;
	case 4:
		key = ui.cKey->text().toLocal8Bit();
		if (key.isEmpty()) {
			io = new IOProtocolDecoratorCrypto(wid, new MyXORCrypto());
		}
		else {
			io = new IOProtocolDecoratorCrypto(wid, new MyXORCrypto(key));
		}
		break;
	default:
		io = new IOProtocolDecoratorCrypto(wid, new MySimpleCrypto());
		break;
	}
	return io;
}
