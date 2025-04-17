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
	QMap<QPushButton*, TaskEntity> taskList;

public:
	TaskRepository();
	~TaskRepository();

	QPushButton* addTask(std::string taskN, std::string taskD);

	void doButton(QPushButton* button);

	size_t getSize();
	QMap<QPushButton*, TaskEntity> getTasks();
	void setTasks(QMap<QPushButton*, TaskEntity> newList);
};

