#pragma once
#include <QString>
#include <QDebug>
#include <QByteArray>
class IOProtocol
{
public:
	virtual ~IOProtocol();
public:
	virtual QByteArray input() = 0;
	virtual void output() = 0;
	virtual void outputOrigin() = 0;
	void setText(QByteArray str) { text = str; };
	QByteArray getText() { return text; };
protected:
	QByteArray text;
};

