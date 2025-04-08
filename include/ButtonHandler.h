#pragma once

#include <qobject.h>
#include <qdebug.h>
#include <qradiobutton.h>
#include "TaskRepository.h"
#include <QVBoxLayout>
#include "AddWindow.h"


class ButtonHandler : public QObject
{
	Q_OBJECT

private:
	TaskRepository taskRepo;
	Ui::Checklist ui;
	AddWindow* addW = new AddWindow();

	void setupWindow();
	void addTask();


public:
	ButtonHandler(Ui::Checklist& ui);
	//ButtonHandler();
	~ButtonHandler();

	void closeWindow();

public slots:
	void addButton();
	void delButton();
	void showAllButton();
};

