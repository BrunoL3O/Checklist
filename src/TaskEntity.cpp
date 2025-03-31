#include "TaskEntity.h"

TaskEntity::TaskEntity()
{
	taskID = -1;
	taskDesc = "";
	taskName = "";
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
