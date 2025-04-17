#include "AddWindow.h"

AddWindow::AddWindow(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	this->setFixedSize(size());
	setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	qDebug() << this;
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

QPlainTextEdit* AddWindow::getDesc()
{
	return ui.taskDescBox;
}

QPlainTextEdit* AddWindow::getTitle()
{
	return ui.taskTitleBox;
}

void AddWindow::showWindow()
{
	
}



