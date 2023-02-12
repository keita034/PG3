#pragma once

#include "TaskDataList.h"
#include "UserDataList.h"
#include"BaseDataControl.h"

class TaskDataControl :public BaseDataControl
{
public:

	TaskDataControl(TaskDataList* taskList, UserDataList* userList);
	~TaskDataControl();

	void Edit() override;

	void Add()override;

	void Sub()override;

private:

	TaskDataList* taskDataList;
	UserDataList* userDataList;
};

