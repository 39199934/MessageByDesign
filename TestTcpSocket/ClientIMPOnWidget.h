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
	
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("�ͻ��˴���")) override;
private:
	Ui::ClientIMPOnWidget ui;
	//void onClickedBtnSend();

	// ͨ�� ClientIMPProtocol �̳�
	virtual void setConnectState(const QString& state) override;
	virtual void appendMessageHistory(const QByteArray& bytes) override;
	virtual QString getMessageForSend() override;
	// ͨ�� ClientIMPProtocol �̳�
	
private slots:
	virtual void onClickedBtnSend() override ;
	void onClickedBtnLink();
	void onClickedSetHost();



	


	// ͨ�� ClientIMPProtocol �̳�
	virtual void setWidgetTitle(const QString& title = QString::fromLocal8Bit("�ͻ��˴���")) override;

};
