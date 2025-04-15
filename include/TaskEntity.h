#pragma once

#include <string>

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
	TaskEntity();
	~TaskEntity();
	std::string getName();
	std::string getDesc();
	int getID();
};

