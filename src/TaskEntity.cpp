#include "TaskEntity.h"

TaskEntity::TaskEntity(int id, std::string taskN, std::string taskD)
{
	taskID = id;
	taskName = taskN;
	taskDesc = taskD;
}

TaskEntity::~TaskEntity()
{

}

std::string TaskEntity::getDesc()
{
	return taskDesc;
}

std::string TaskEntity::getName()
{
	return taskName;
}

int TaskEntity::getID()
{
	return taskID;
}

QString TaskEntity::toString()
{
	return QString::fromStdString("--------------------\nTask Title: " + taskName +
		"\nTask Description: " + taskDesc +
		"\nID: " + std::to_string(taskID) +
		"\n");
}