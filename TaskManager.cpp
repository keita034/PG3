#include "TaskManager.h"

#include<iostream>

void TaskManager::TaskOperation()
{
	std::cout << "[タスク関係操作]" << std::endl;
	std::cout << "1.タスク追加" << std::endl;
	std::cout << "2.タスク編集" << std::endl;
	std::cout << "3.タスク削除" << std::endl;
	std::cout << "4.戻る" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	std::cout << std::endl;
}

void TaskManager::UserDataOperation()
{

	std::cout << "[担当者関係操作]" << std::endl;
	std::cout << "1.担当者追加" << std::endl;
	std::cout << "2.担当者編集" << std::endl;
	std::cout << "3.担当者削除" << std::endl;
	std::cout << "4.戻る" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	std::cout << std::endl;
}

void TaskManager::DrawOperation()
{
}

void TaskManager::Operation(int num)
{
	switch (num)
	{
	case 1:
		TaskOperation();
		break;
	case 2:
		UserDataOperation();
		break;
	case 3:
		DrawOperation();
		break;
	default:
		break;
	}



	std::cin >> operationNum;
	system("cls");

	switch (operationNum)
	{
	case 1:
		controls[num - 1]->Add();
		break;
	case 2:
		controls[num - 1]->Edit();
		break;
	case 3:
		controls[num - 1]->Sub();
		break;
	default:
		break;
	}
}

TaskManager::TaskManager()
{
	userLists = std::make_unique<UserDataList>();
	taskLists = std::make_unique<TaskDataList>();
	controls[1] = std::make_unique<UserDataControl>(userLists.get());
	controls[0] = std::make_unique<TaskDataControl>(taskLists.get(), userLists.get());
	//controls[0] = std::make_unique<UserDataControl>(lists.get());
}

TaskManager::~TaskManager()
{
}
