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

	//�v�f�̑���̑���ԍ�
	int operationNum = 0;

	while (true)
	{
		std::cout << "[�^�X�N�Ǘ��\�t�g]" << std::endl;
		std::cout << "1.�^�X�N" << std::endl;
		std::cout << "2.�S����" << std::endl;
		std::cout << "3.�\��" << std::endl;

		std::cout << "----------------------------------" << std::endl;
		std::cout << "���삵������ނ�I�����Ă�������" << std::endl;

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
