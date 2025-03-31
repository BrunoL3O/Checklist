#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(Ui::Checklist& ui) : UI(ui)
{

}


//ButtonHandler::ButtonHandler()
//{
//
//}

ButtonHandler::~ButtonHandler()
{

}


void ButtonHandler::addButton()
{

	// label adding
	// TODO : add to task repository 

	QLabel* newLabel = new QLabel(UI.taskBox);
	newLabel->setText("Task" + QString::number(taskRepo.getCount()));
	newLabel->setGeometry(newLabel->geometry().x(),
		(UI.taskBox->children().count() - 2) * 20,
		newLabel->geometry().width(),
		newLabel->geometry().height());

	QVBoxLayout* vbox;

	if (UI.taskBox->layout())
	{
		vbox = qobject_cast<QVBoxLayout*>(UI.taskBox->layout());

	}
	else
	{
		vbox = new QVBoxLayout();
	}

	vbox->addWidget(newLabel);


	UI.taskBox->setLayout(vbox);

	qDebug() << UI.taskBox->children().count();


	//addW.show();
}

void ButtonHandler::delButton()
{
	// delete 
}

void ButtonHandler::showAllButton()
{
	qDebug() << UI.taskBox->children().count();
}

void ButtonHandler::setupWindow()
{

}
