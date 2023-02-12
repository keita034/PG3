#pragma once
#include<memory>
#include<array>

#include"UserDataControl.h"
#include"UserDataList.h"
#include"TaskDataControl.h"
#include"TaskDataList.h"

class TaskManager
{
public:

	/// <summary>
	/// ƒ^ƒXƒNŠÖŒW‘€ì
	/// </summary>
	void TaskOperation();

	/// <summary>
	/// ’S“–ÒŠÖŒW‘€ì
	/// </summary>
	void UserDataOperation();

	/// <summary>
	/// •\¦ŠÖŒW‘€ì
	/// </summary>
	void DrawOperation();

	void Operation(int num);

	TaskManager();
	~TaskManager();

private:

	std::array<std::unique_ptr<BaseDataControl>, 3>controls;

	std::unique_ptr<UserDataList> userLists;
	std::unique_ptr<TaskDataList> taskLists;

	//—v‘f‚Ì‘€ì‚Ì‘€ì”Ô†
	int operationNum = 0;
};

