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
	/// �^�X�N�֌W����
	/// </summary>
	void TaskOperation();

	/// <summary>
	/// �S���Ҋ֌W����
	/// </summary>
	void UserDataOperation();

	/// <summary>
	/// �\���֌W����
	/// </summary>
	void DrawOperation();

	void Operation(int num);

	TaskManager();
	~TaskManager();

private:

	std::array<std::unique_ptr<BaseDataControl>, 3>controls;

	std::unique_ptr<UserDataList> userLists;
	std::unique_ptr<TaskDataList> taskLists;

	//�v�f�̑���̑���ԍ�
	int operationNum = 0;
};

