#include "TaskManager.h"

#include<iostream>

void TaskManager::TaskOperation()
{
	std::cout << "[�^�X�N�֌W����]" << std::endl;
	std::cout << "1.�^�X�N�ǉ�" << std::endl;
	std::cout << "2.�^�X�N�ҏW" << std::endl;
	std::cout << "3.�^�X�N�폜" << std::endl;
	std::cout << "4.�߂�" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

	std::cout << std::endl;
}

void TaskManager::UserDataOperation()
{

	std::cout << "[�S���Ҋ֌W����]" << std::endl;
	std::cout << "1.�S���Ғǉ�" << std::endl;
	std::cout << "2.�S���ҕҏW" << std::endl;
	std::cout << "3.�S���ҍ폜" << std::endl;
	std::cout << "4.�߂�" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

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
