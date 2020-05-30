#pragma once
#include "IOProtocol.h"
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
class IOFile :
	public IOProtocol
{
public:
	IOFile(QString file_name = QString());
public:
	virtual QByteArray input() override;
	virtual void output() override;
	virtual void outputOrigin() override;
	void setText(QByteArray str) { text = str; };
	QByteArray getText() { return text; };
protected:
	//QByteArray text;
	QString fileName;
	QFile fp;
};

