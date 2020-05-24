#include "TextBody.h"

TextBody::TextBody(const QString& text_content,QObject *parent)
	: BodyOfMessageProtocol(parent)
{
	insertJsonValue("textMessage", text_content);
}

TextBody::~TextBody()
{
}

QString TextBody::getBodyType()
{
	return "textMessage";
}
