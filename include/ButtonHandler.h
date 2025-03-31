#pragma once

#include <qobject.h>
#include <qdebug.h>
#include <qradiobutton.h>
#include "TaskRepository.h"
//#include "DialogWindow.h"
#include <QVBoxLayout>


class ButtonHandler : public QObject
{
	Q_OBJECT

private:
	TaskRepository taskRepo;
	Ui::Checklist& UI;
	//DialogWindow addW;
	//QVBoxLayout *layout;
	//Ui::Dialog& addUI;

	void setupWindow();


public:
	ButtonHandler(Ui::Checklist& ui);
	//ButtonHandler();
	~ButtonHandler();

public slots:
	void addButton();
	void delButton();
	void showAllButton();
};

