#include "TaskRepository.h"

TaskRepository::TaskRepository()
{

}

TaskRepository::~TaskRepository()
{

}

QPushButton* TaskRepository::addTask(std::string taskN, std::string taskD)
{
    TaskEntity newTask = TaskEntity(taskList.count() + 1, taskN, taskD);
    QPushButton* pairedButton = new QPushButton();
    pairedButton->setText(QString::fromStdString(taskN));
    pairedButton->setToolTip(QString::fromStdString(taskD));

    doButton(pairedButton);

    taskList.insert(pairedButton, newTask);
    return pairedButton;
}

void TaskRepository::doButton(QPushButton* button)
{
    /// do button
    /// make it fancy
    /// 
    /// this will be done later. i do not wish to code ui anymore
}

size_t TaskRepository::getSize()
{
    return taskList.size();
}

QMap<QPushButton*, TaskEntity> TaskRepository::getTasks()
{
    return taskList;
}

TaskEntity TaskRepository::getTask(QPushButton* buton)
{
    return taskList.find(buton).value();
}

void TaskRepository::removeTask(QPushButton* toRemove)
{
    taskList.remove(toRemove);
}

void TaskRepository::setTasks(QMap<QPushButton*, TaskEntity> newList)
{
    taskList = newList;
}
