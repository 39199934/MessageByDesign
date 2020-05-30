#include "IOFile.h"

IOFile::IOFile(QString file_name):
	IOProtocol(),
	fileName(file_name)
{
}

QByteArray IOFile::input()
{
	QFileInfo info(fileName);
	QFile *fp;
	if (!info.exists()) {
		auto fn = QFileDialog::getOpenFileName(nullptr, QString::fromLocal8Bit("请选择需读入的文件"), "./");
		fileName = fn;
		
	}
	fp = new QFile(fileName);
	fp->open(QIODevice::OpenModeFlag::ReadOnly);
	text = fp->readAll();
	delete fp;
	return text;
}

void IOFile::output()
{
	fileName = "";
	QFileInfo info(fileName);
	QFile* fp;
	if (!info.exists()) {
		auto fn = QFileDialog::getSaveFileName(nullptr, QString::fromLocal8Bit("请选择需输出的文件"), "./");
		fileName = fn;

	}
	fp = new QFile(fileName);
	fp->open(QIODevice::OpenModeFlag::WriteOnly);
	fp->write(text);
	//text = fp->readAll();
	delete fp;
}

void IOFile::outputOrigin()
{
	fileName = "";
	QFileInfo info(fileName);
	
	QFile* fp;
	if (!info.exists()) {
		auto fn = QFileDialog::getSaveFileName(nullptr, QString::fromLocal8Bit("请选择需输出的文件"), "./");
		fileName = fn;

	}
	fp = new QFile(fileName);
	fp->open(QIODevice::OpenModeFlag::WriteOnly);
	fp->write(text);
	//text = fp->readAll();
	delete fp;
}
