#pragma once
#include "ClientIMPProtocol.h"
#include <iostream>
using namespace std;
class ClientIMPOnStd :
	public ClientIMPProtocol
{
	// ͨ�� ClientIMPProtocol �̳�
	virtual void setConnectState(const QString& state) override;
	virtual void appendMessageHistory(const QByteArray& bytes) override;
	virtual QString getMessageForSend() override;
	virtual void onClickedBtnSend() override;

	// ͨ�� ClientIMPProtocol �̳�
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("�ͻ��˴���")) override;

	// ͨ�� ClientIMPProtocol �̳�
	virtual void setWidgetTitle(const QString& title = QString::fromLocal8Bit("�ͻ��˴���")) override;
};

