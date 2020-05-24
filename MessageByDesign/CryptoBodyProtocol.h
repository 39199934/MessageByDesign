#pragma once
//װ����Ļ��࣬ױ��ģʽ���м���
#include "BodyOfMessageProtocol.h"

class CryptoBodyProtocol : public BodyOfMessageProtocol
{
	Q_OBJECT

public:
	CryptoBodyProtocol(BodyOfMessageProtocol* body_for_crypto, QObject *parent);
	virtual ~CryptoBodyProtocol();

public:
	
	
	virtual HeadOfMessage* buildHead();
	
	QString getBodyType();
	virtual void view(QTextBrowser* browser) override;


	//�������๹�캯���е���this->setBagByteArray(body_for_crypto->getBagByteArray());
	//���ؼ�������
	virtual QString getCryptoType() = 0;
	//��ȡ���ܺ������
	virtual QByteArray getBagByteArray() = 0;
	//���Ǽ������ݽ��м��ܺ�д������
	virtual void setBagByteArray(const QByteArray& bytes) = 0;
	
protected:
	BodyOfMessageProtocol* body;
};
