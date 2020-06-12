#pragma once
#include "ClientIMPProtocol.h"
#include <iostream>
using namespace std;
class ClientIMPOnStd :
	public ClientIMPProtocol
{
	// 通过 ClientIMPProtocol 继承
	virtual void setConnectState(const QString& state) override;
	virtual void appendMessageHistory(const QByteArray& bytes) override;
	virtual QString getMessageForSend() override;
	virtual void onClickedBtnSend() override;

	// 通过 ClientIMPProtocol 继承
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("客户端窗口")) override;

	// 通过 ClientIMPProtocol 继承
	virtual void setWidgetTitle(const QString& title = QString::fromLocal8Bit("客户端窗口")) override;
};

