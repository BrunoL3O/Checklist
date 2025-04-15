#pragma once

#include <vector>
#include "TaskEntity.h"
#include <map>
#include "ui_Checklist.h"
#include "ui_AddWindow.h"


/// <summary>
/// This class exists to keep track of all the tasks in the QGroupBox "taskBox".
/// 
/// </summary>

class TaskRepository
{
private:
	QVector<QPushButton*> buttonList;
	QMap<QPushButton*, TaskEntity> taskList;

public:
	/*TaskRepository();
	~TaskRepository();*/
	size_t getCount();
	QMap<QPushButton*, TaskEntity> getTasks();
	void setTasks(QMap<QPushButton*, TaskEntity> newList);
};

