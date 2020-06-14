#include "ServerIMPWidget.h"

ServerIMPWidget::ServerIMPWidget(QWidget *parent)
	: QWidget(parent),
	currentWidget(nullptr)
{
	ui.setupUi(this);
	//ui.cClientsList->setModel()
	connect(ui.cClientsList, &QTableView::clicked, this, &ServerIMPWidget::slotClientsListClicked);
}

ServerIMPWidget::~ServerIMPWidget()
{
}

void ServerIMPWidget::addClientWidget(QWidget* clientWidget)
{
	if (currentWidget != nullptr) {
		currentWidget->close();
	}
	clientWidget->setParent(ui.cWidget);
	clientWidget->setSizePolicy(QSizePolicy::QSizePolicy::Expanding, QSizePolicy::QSizePolicy::Expanding);
	clientWidget->show();
	/*
	auto lay = new QVBoxLayout();
	//clientWidget->setSizePolicy(QSizePolicy::QSizePolicy::Expanding, QSizePolicy::QSizePolicy::Expanding);
	lay->addWidget(clientWidget);
	
	auto layout = ui.cWidget->layout();
	if (layout != nullptr) {
		layout->deleteLater();
	}
	ui.cWidget->setLayout(lay);
	//clientWidget->show();
	ui.cWidget->show();
	ui.cWidget->update();
	*/

	/*
	layout->removeWidget(currentWidget);

	layout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
	
	layout->addWidget(clientWidget);
	*/
	currentWidget = clientWidget;
}

void ServerIMPWidget::setClienstListModel(QAbstractItemModel* model)
{
	ui.cClientsList->setModel(model);
}

void ServerIMPWidget::refreshClientsList()
{
	ui.cClientsList->viewport()->update();
	
}

void ServerIMPWidget::slotClientsListClicked(const QModelIndex& index)
{
	emit signalClientsListClicked(index);
}
