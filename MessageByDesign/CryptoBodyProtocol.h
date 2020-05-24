#pragma once
//装饰类的基类，妆饰模式的中间类
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


	//需在子类构造函数中调用this->setBagByteArray(body_for_crypto->getBagByteArray());
	//返回加密类型
	virtual QString getCryptoType() = 0;
	//获取解密后的数据
	virtual QByteArray getBagByteArray() = 0;
	//将非加密数据进行加密后写入数据
	virtual void setBagByteArray(const QByteArray& bytes) = 0;
	
protected:
	BodyOfMessageProtocol* body;
};
