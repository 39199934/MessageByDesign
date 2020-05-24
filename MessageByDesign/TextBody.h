#pragma once

#include "BodyOfMessageProtocol.h"

class TextBody : public BodyOfMessageProtocol
{
	Q_OBJECT

public:
	TextBody(const QString& text_content,QObject *parent);
	~TextBody();

protected:
	virtual QString getBodyType() override;
};
