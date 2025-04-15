#include "TaskRepository.h"

// constructor + destructor 

size_t TaskRepository::getCount()
{
    return taskList.size();
}

QMap<QPushButton*, TaskEntity> TaskRepository::getTasks()
{
    return taskList;
}

void TaskRepository::setTasks(QMap<QPushButton*, TaskEntity> newList)
{
    taskList = newList;
}
