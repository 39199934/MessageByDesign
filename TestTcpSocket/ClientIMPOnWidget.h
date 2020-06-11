#pragma once

#include <QWidget>
#include "ui_ClientIMPOnWidget.h"
#include "ClientIMPProtocol.h"
#include <QPushButton>

class ClientIMPOnWidget : public QWidget,public ClientIMPProtocol
{
	Q_OBJECT

public:
	ClientIMPOnWidget(QWidget *parent = Q_NULLPTR);
	~ClientIMPOnWidget();
	

private:
	Ui::ClientIMPOnWidget ui;
	//void onClickedBtnSend();

	// ͨ�� ClientIMPProtocol �̳�
	virtual void setConnectState(const QString& state) override;
	virtual void appendMessageHistory(const QByteArray& bytes) override;
	virtual QString getMessageForSend() override;
	// ͨ�� ClientIMPProtocol �̳�
	virtual void showWidget(const QString& title = QString::fromLocal8Bit("�ͻ��˴���")) override;
private slots:
	virtual void onClickedBtnSend() override ;


	

};
