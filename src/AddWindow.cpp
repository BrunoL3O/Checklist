#include "AddWindow.h"

AddWindow::AddWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(size());
	setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}

AddWindow::~AddWindow()
{
	
}

void AddWindow::setButtonHandler(ButtonHandler* bttnH)
{
	buttonHandler = bttnH;
}

QPushButton* AddWindow::getAdd()
{
	return ui.Add;
}

QPushButton* AddWindow::getCancel()
{
	return ui.Cancel;
}

void AddWindow::showWindow()
{
	
}



