#include "ButtonHandler.h"
#include "AddWindow.h"
#include "Checklist.h"

ButtonHandler::ButtonHandler(Ui::Checklist& ui, AddWindow* addWindow, Checklist* chkl) : ui(ui), addW(addWindow), chklst(chkl)
{
	ui.sAreaContent->setGeometry(ui.taskBox->geometry());
}

ButtonHandler::~ButtonHandler()
{
	/// This, kids, is why you study pointers before making projects
	/// in the *memory management heavy* language.
	/// I'm ashamed to admit how much this took. I only pray this is proper design, since 
	/// addW is spawned by the add button.

	//if (addW)
	//{
	//	addW->close();
	//	delete addW;
	//	addW = nullptr;
	//}
}

void ButtonHandler::addButton()
{

	// label adding
	// TODO : add to task repository 

	QLabel* newLabel = new QLabel(ui.taskBox);

	labelMaker(*newLabel, taskRepo);

	/// Debatable if this does anything but I'll keep it there . . .
	newLabel->installEventFilter(this);

	newLabel->resize(QSize(155, 30));

	/*QScrollArea* scrollArea = new QScrollArea(ui.taskBox);

	QWidget* areaThing = new QWidget();
	QVBoxLayout* areaLayout = new QVBoxLayout(areaThing);
	areaLayout->addWidget(newLabel);*/

	QVBoxLayout* vbox;

	if (ui.sAreaContent->layout())
	{
		vbox = qobject_cast<QVBoxLayout*>(ui.sAreaContent->layout());
	}
	else
	{
		vbox = new QVBoxLayout();
	}


	/*vbox->setSpacing(10);
	vbox->addWidget(newLabel);
	ui.sAreaContent->setLayout(vbox);*/

	//ui.taskBox->setLayout(vbox);

	if (addW)
	{
		addW->show();
	}
	else
	{
		addW = new AddWindow();
		addW->setButtonHandler(this);
		addW->show();

		connect(addW->getAdd(), &QPushButton::clicked, this, &ButtonHandler::addTask);
		connect(addW->getCancel(), &QPushButton::clicked, this, &ButtonHandler::cancelOperation);

		chklst->setAddWindow(addW);
	}

	qDebug() << addW;
}

void ButtonHandler::delButton()
{
	// delete 

	//addW->hide();

	if (lastPress != nullptr)
	{
		QVBoxLayout* boxL = qobject_cast<QVBoxLayout*>(ui.sAreaContent->layout());
		boxL->removeWidget(lastPress);
		taskRepo.removeTask(lastPress);
		lastPress->deleteLater();
		lastPress = nullptr;
		ui.taskDesc->clear();
	}
}

void ButtonHandler::showAllButton()
{
	qDebug() << taskRepo.getSize();
}

void ButtonHandler::addTask()
{
	std::string str1, str2;
	str1 = addW->getTitle()->toPlainText().toStdString();
	str2 = addW->getDesc()->toPlainText().toStdString();
	QPushButton* buton = taskRepo.addTask(str1, str2);
	

	/// lambda functions have to be the best thing I know in this language
	/// what do you mean I can have this much convenience at my fingertips??
	/// jokes aside,
	/// this makes it so the button sends ButtonHandler the clicked signal,
	/// then it calls the lambda function :
	/// we get the task, and display the task's description
	/// and the last button (useful for delete shenanigans..)

	/// lambda function dub counter : 2


	connect(buton, &QPushButton::clicked, this, [this, buton]() {
		TaskEntity task = taskRepo.getTask(buton);
		ui.taskDesc->setPlainText(QString::fromStdString(task.getDesc()));
		lastPress = buton;
		qDebug() << lastPress;
		});

	QVBoxLayout* vbox;

	if (ui.sAreaContent->layout())
	{
		vbox = qobject_cast<QVBoxLayout*>(ui.sAreaContent->layout());
	}
	else
	{
		vbox = new QVBoxLayout();
		vbox->setSpacing(10);
	}

	vbox->addWidget(buton);
	ui.sAreaContent->setLayout(vbox);
	//ui.taskBox->setLayout(vbox);

	delete addW;
	addW = nullptr;
	chklst->setAddWindow(addW);

}

void ButtonHandler::cancelOperation()
{
	/// I *could* just hide it, yes.
	/// But that doesn't clear the fields. 
	/// And it's kind of a pain to get to them.

	qDebug() << addW;

	delete addW;
	addW = nullptr;
	chklst->setAddWindow(addW);
}


void ButtonHandler::labelMaker(QLabel& newLabel, TaskRepository taskRepo)
{
	newLabel.setText("Task" + QString::number(taskRepo.getSize()));

	newLabel.setFrameStyle(QFrame::StyledPanel | QFrame::Shadow::Sunken);

	newLabel.setGeometry(newLabel.geometry().x(),
		(ui.taskBox->children().count() - 2) * 20,
		170,
		30);

	newLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

}