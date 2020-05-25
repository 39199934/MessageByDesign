#include "MessageByDesign.h"
#include "CryptoMine.h"

MessageByDesign::MessageByDesign(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	BagProtocol bag;
	bag.view(ui.messagesShower);
	HeadOfMessage head(this);
	head.setType("text");
	head.setBodySize(100);
	head.setCryptoType("base64");
	head.setBodyUuid("lskdfj");
	//head.view(ui.messagesShower);

	TextBody tb("hi,server", this);
	tb.view(ui.messagesShower);
	auto hotb = tb.buildHead();
	//hotb->view(ui.messagesShower);
	CryptoMine cb64(&tb, this);
	cb64.view(ui.messagesShower);
	auto cb64h = cb64.buildHead();
	cb64h->view(ui.messagesShower);
	auto doc = cb64.getJsonFromBagByteArray();
	qDebug() << doc.object();
	delete hotb;
}
