#pragma once

#include <qobject.h>
#include <qdebug.h>
#include <qradiobutton.h>
#include <QVBoxLayout>
#include "qscrollarea.h"
#include "TaskRepository.h"

class AddWindow;
class Checklist;

class ButtonHandler : public QObject
{
	Q_OBJECT

private:
	Ui::Checklist ui;
	Ui::AddWindow ui2;

	AddWindow* addW;
	Checklist* chklst;
	//QLabel* lastLabelSelected;

	// void setupWindow();

public:
	TaskRepository taskRepo;

	ButtonHandler(Ui::Checklist& ui, AddWindow* addWindow, Checklist* chkl);
	//ButtonHandler();
	~ButtonHandler();

	/*bool getLastLabel(QObject* labelWatched, QEvent* mouseClickEvent);
	void closeWindow();*/
	void labelMaker(QLabel& newLabel, TaskRepository taskRepo);

public slots:
	void addButton();
	void delButton();
	void showAllButton();

	void addTask();
	void cancelOperation();
};

