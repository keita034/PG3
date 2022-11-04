#include <stdio.h>
#include"MyList.h"
#include<list>

template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOperationNum);


int main()
{
	Mylist<int> list;

	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	list.Insert(3, 2);

	list.ChangeValue(8, 3);

	list.Dump();

	list.SpecifyElement(1);
	int operationNum = 0;
	int displayOperationNum = 0;


	while (true)
	{
		std::cout << "[�v�f�̑���]" << std::endl;
		std::cout << "1.�v�f�̕\��" << std::endl;
		std::cout << "2.�v�f�̑}��" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.�v�f�̕ҏW" << std::endl;
			std::cout << "4.�v�f�̍폜" << std::endl;
		}
		
		std::cout << "5.�v�f�̕��ёւ�(�I�v�V����)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "�����I�����Ă�������" << std::endl;

		std::cout << std::endl;
		
		if (operationNum == 0)
		{
			std::cin >> operationNum;
		}
		system("cls");

		switch (operationNum)
		{
		case 1:
			Display(list, operationNum, displayOperationNum);
			break;
		}
	}

	return 0;
}

template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOperationNum)
{
	std::cout << "[�v�f�̕\��]" << std::endl;
	std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;
	std::cout << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:
		std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
		std::cout << "�v�f��:" << list.Size() << std::endl;
		//�ꗗ�\��
		list.Dump();

		break;
	case 2:
		std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
		std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		list.SpecifyElement(specifyNum);

		break;

	case 9:
		operationNum = 0;
		break;
	}

	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
		std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;
		std::cin >> displayOperationNum;
		system("cls");
		switch (displayOperationNum)
		{
		case 1:
			operationNum = 1;
			break;
		case 2:
			operationNum = 0;
			break;
		default:
			break;
		}
	}
}