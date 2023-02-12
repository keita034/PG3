#include <stdio.h>
#include<list>
#include<vector>
#include<iostream>
#include<memory>

#include"TaskManager.h"
#include"UserDataList.h"
#include"Constant.h"

int main()
{
	std::unique_ptr<TaskManager> taskManager;
	taskManager = std::make_unique<TaskManager>();

	UserDataList lis;

	USERDATA data = {"simi","LE2B"};

	lis.AddData(data);

	//要素の操作の操作番号
	int operationNum = 0;

	while (true)
	{
		std::cout << "[タスク管理ソフト]" << std::endl;
		std::cout << "1.タスク" << std::endl;
		std::cout << "2.担当者" << std::endl;
		std::cout << "3.表示" << std::endl;

		std::cout << "----------------------------------" << std::endl;
		std::cout << "操作したい種類を選択してください" << std::endl;

		std::cout << std::endl;

		std::cin >> operationNum;

		system("cls");

		switch (operationNum)
		{
		case 1:
		case 2:
			taskManager->Operation(operationNum);
			break;
		case 3:
			taskManager->DrawOperation();
				break;
		default:
			break;
		}

	}

	return 0;
}
