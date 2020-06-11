#pragma once

#include "BagProtocol.h"

class HeadOfMessage : public BagProtocol
{
	Q_OBJECT

public:
	HeadOfMessage(QObject *parent);
	~HeadOfMessage();
	void setType(const QString& type);
	QString getType();
	void setCryptoType(const QString& crypto_type);
	QString getCryptoType();
	void setBodyUuid(const QString& body_uuid);
	QString getBodyUuid();
	void setBodySize(int body_size);
	int getBodySize();
	virtual void view(QTextBrowser* browser) override;
};
  