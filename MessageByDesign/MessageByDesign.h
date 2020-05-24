#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MessageByDesign.h"
#include "BagProtocol.h"
#include "HeadOfMessage.h"
#include "TextBody.h"
#include "CryptoBase64.h"

class MessageByDesign : public QMainWindow
{
	Q_OBJECT

public:
	MessageByDesign(QWidget *parent = Q_NULLPTR);

private:
	Ui::MessageByDesignClass ui;
};
