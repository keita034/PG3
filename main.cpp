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
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.要素の編集" << std::endl;
			std::cout << "4.要素の削除" << std::endl;
		}
		
		std::cout << "5.要素の並び替え(オプション)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "操作を選択してください" << std::endl;

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
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:
		std::cout << "[要素の一覧表示]" << std::endl;
		std::cout << "要素数:" << list.Size() << std::endl;
		//一覧表示
		list.Dump();

		break;
	case 2:
		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

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
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;
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