#pragma once

#include <string>
#include "qstring.h"
#include "qdatetime.h"

class TaskEntity
{

	/// Each QPushButton has one associated TaskEntity.
	/// taskName is the text that appears on the button,
	/// and taskDesc is the text that appears when pressing the button.

private:
	std::string taskName;
	std::string taskDesc;
	/// QDate date;
	int taskID;

public:
	TaskEntity(int id, std::string taskName, std::string taskDesc);
	~TaskEntity();

	std::string getName();
	std::string getDesc();
	int getID();

	QString toString();
};

