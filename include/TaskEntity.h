#pragma once

#include <string>
#include "qstring.h"

class TaskEntity
{

	/// Each QPushButton has one associated TaskEntity.
	/// taskName is the text that appears on the button,
	/// and taskDesc is the text that appears when holding mouse over the button.

private:
	std::string taskName;
	std::string taskDesc;
	int taskID;

public:
	TaskEntity(int id, std::string taskName, std::string taskDesc);
	~TaskEntity();

	std::string getName();
	std::string getDesc();
	int getID();

	QString toString();
};

