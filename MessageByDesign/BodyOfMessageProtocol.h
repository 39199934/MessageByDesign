#pragma once

#include "BagProtocol.h"
#include "HeadOfMessage.h"

class BodyOfMessageProtocol : public BagProtocol
{
	Q_OBJECT

public:
	BodyOfMessageProtocol(QObject *parent);
	~BodyOfMessageProtocol();

	virtual QString getCryptoType() ;
	virtual void view(QTextBrowser* browser) override;
	virtual HeadOfMessage* buildHead();
	virtual QString getBodyType() = 0;
	
	int getBodySize();
};
