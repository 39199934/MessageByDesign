#pragma once

#include <QWidget>
#include "ui_ClientIMPOnWidget.h"
#include "ClientIMPProtocol.h"
#include <QPushButton>
#include <QDiaLog>
#include "SetHostInfoDiaog.h"
class ClientIMPOnWidget : public QWidget,public ClientIMPProtocol
{
	Q_OBJECT

public:
	ClientIMPOnWidget(QWidget *parent = Q_NULLPTR);
	~ClientIMPOnWidget();
	
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("客户端窗口")) override;
private:
	Ui::ClientIMPOnWidget ui;
	//void onClickedBtnSend();

	// 通过 ClientIMPProtocol 继承
	virtual void setConnectState(const QString& state) override;
	virtual void appendMessageHistory(const QByteArray& bytes) override;
	virtual QString getMessageForSend() override;
	// 通过 ClientIMPProtocol 继承
	
private slots:
	virtual void onClickedBtnSend() override ;
	void onClickedBtnLink();
	void onClickedSetHost();



	


	// 通过 ClientIMPProtocol 继承
	virtual void setWidgetTitle(const QString& title = QString::fromLocal8Bit("客户端窗口")) override;

};
