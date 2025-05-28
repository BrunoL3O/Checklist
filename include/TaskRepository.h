#pragma once

#include <vector>
#include "TaskEntity.h"
#include <map>
#include "ui_Checklist.h"
#include "ui_AddWindow.h"
#include "qjsonarray.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qfile.h"
#include "qdir.h"
#include <QStandardPaths>


/// <summary>
/// This class exists to keep track of all the tasks in the QGroupBox "taskBox".
/// 
/// </summary>

class TaskRepository
{
private:
	QMap<QPushButton*, TaskEntity> taskList;

	QJsonArray taskJSON;
	QString path;

public:
	TaskRepository();
	~TaskRepository();

	QPushButton* addTask(std::string taskN, std::string taskD);

	void doButton(QPushButton* button);

	size_t getSize();
	QMap<QPushButton*, TaskEntity> getTasks();
	TaskEntity getTask(QPushButton* buton);
	
	void removeTask(QPushButton* toRemove);
	void setTasks(QMap<QPushButton*, TaskEntity> newList);

	QJsonDocument load();
	void save();
	void loadRepo();
};

