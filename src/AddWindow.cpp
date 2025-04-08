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

void AddWindow::showWindow()
{
	
}
