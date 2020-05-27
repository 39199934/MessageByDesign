#pragma once
#include <QString>
#include <QDebug>
class IOProtocol
{
public:
	virtual ~IOProtocol();
public:
	virtual QString input() = 0;
	virtual void output() = 0;
	virtual void outputOrigin() = 0;
	void setText(QString str) { text = str; };
	QString getText() { return text; };
protected:
	QString text;
};

