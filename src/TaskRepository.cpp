#include "TaskRepository.h"

TaskRepository::TaskRepository()
{
    path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Checklist_Tasks.json";

    QJsonDocument doc = load();
    
    QJsonObject obj = doc.object();
    taskJSON = obj["tasks"].toArray();

    loadRepo();
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

    QJsonObject task;
    task["taskName"] = QString::fromStdString(taskN);
    task["taskDesc"] = QString::fromStdString(taskD);

    taskJSON.append(task);

    save();


    return pairedButton;
}

void TaskRepository::doButton(QPushButton* button)
{
    /// i think they're good looking enough for now...

    button->setMinimumWidth(155);
    button->setFixedHeight(35);

    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
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

    for (int i = 0; i < taskJSON.size(); i++)
    {
        QJsonObject task = taskJSON[i].toObject();
        if (task["taskName"].toString() == toRemove->text())
        {
            taskJSON.removeAt(i);
        }
    }

    save();
}

void TaskRepository::setTasks(QMap<QPushButton*, TaskEntity> newList)
{
    taskList = newList;
}

void TaskRepository::save()
{
    QFile file(path);
    QJsonObject obj;
    obj["tasks"] = taskJSON;

    QJsonDocument doc(obj);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug("something wrong with opening the JSON file at TaskRepository::save()");
        exit(1);
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

void TaskRepository::loadRepo()
{
    for (int i = 0; i < taskJSON.size(); i++)
    {
        QPushButton* newButton = new QPushButton;
        QJsonObject obj = taskJSON[i].toObject();

        newButton->setText(obj["taskName"].toString());
        doButton(newButton);
        TaskEntity newTask(i, obj["taskName"].toString().toStdString(), obj["taskDesc"].toString().toStdString());

        taskList.insert(newButton, newTask);
    }
}

QJsonDocument TaskRepository::load()
{
    QFile file(path);
    if (file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QByteArray JSONdata = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(JSONdata);
        return doc;
    }
    else
    {
        /// If the file doesn't exist, *safely* create one

        QJsonObject newObj;
        newObj["tasks"] = QJsonArray();

        QJsonDocument JSONdoc(newObj);
        QFile newFile(path);

        newFile.write(JSONdoc.toJson(QJsonDocument::Indented));
        newFile.close();

        return JSONdoc;
    }
}

