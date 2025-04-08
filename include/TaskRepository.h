#pragma once

#include <vector>
#include "TaskEntity.h"
#include "ui_Checklist.h"
#include "ui_AddWindow.h"


/// <summary>
/// This class exists to keep track of all the tasks in the QGroupBox "taskBox".
/// 
/// </summary>

class TaskRepository
{
private:
	std::vector<TaskEntity> taskList;
	std::vector<QPushButton> buttonList;
public:
	/*TaskRepository();
	~TaskRepository();*/
	size_t getCount();
};

