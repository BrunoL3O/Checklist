#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(Ui::Checklist& ui) : ui(ui)
{
	
}

ButtonHandler::~ButtonHandler()
{
	/// This, kids, is why you study pointers before making projects
	/// in the *memory management heavy* language.
	/// I'm ashamed to admit how much this took. I only pray this is proper design, since 
	/// addW is spawned by the add button.

	addW->close();
	delete addW;
}

void ButtonHandler::closeWindow()
{	

}


void ButtonHandler::addButton()
{

	// label adding
	// TODO : add to task repository 

	/*qDebug() << ui.taskBox->children();

	QLabel* newLabel = new QLabel(ui.taskBox);

	newLabel->setText("Task" + QString::number(taskRepo.getCount()));

	newLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Shadow::Sunken);

	newLabel->setMaximumSize(QSize(170, 30));

	newLabel->setGeometry(newLabel->geometry().x(),
		(ui.taskBox->children().count() - 2) * 20,
		170,
		30);

	QVBoxLayout* vbox;

	if (ui.taskBox->layout())
	{
		vbox = qobject_cast<QVBoxLayout*>(ui.taskBox->layout());

	}
	else
	{
		vbox = new QVBoxLayout();
	}

	vbox->addWidget(newLabel);


	ui.taskBox->setLayout(vbox);

	qDebug() << ui.taskBox->children().count();*/


	addW->show();
	ui.centralWidget->setEnabled(false);
}

void ButtonHandler::delButton()
{
	// delete 

	addW->hide();
}

void ButtonHandler::showAllButton()
{
	qDebug() << ui.taskBox->children().count();                 
}

void ButtonHandler::setupWindow()
{

}

void ButtonHandler::addTask()
{

}
