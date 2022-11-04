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
		std::cout << "[—v‘f‚Ì‘€ì]" << std::endl;
		std::cout << "1.—v‘f‚Ì•\Ž¦" << std::endl;
		std::cout << "2.—v‘f‚Ì‘}“ü" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.—v‘f‚Ì•ÒW" << std::endl;
			std::cout << "4.—v‘f‚Ìíœ" << std::endl;
		}
		
		std::cout << "5.—v‘f‚Ì•À‚Ñ‘Ö‚¦(ƒIƒvƒVƒ‡ƒ“)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

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
	std::cout << "[—v‘f‚Ì•\Ž¦]" << std::endl;
	std::cout << "1.—v‘f‚Ìˆê——•\Ž¦" << std::endl;
	std::cout << "2.‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;
	std::cout << std::endl;
	std::cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:
		std::cout << "[—v‘f‚Ìˆê——•\Ž¦]" << std::endl;
		std::cout << "—v‘f”:" << list.Size() << std::endl;
		//ˆê——•\Ž¦
		list.Dump();

		break;
	case 2:
		std::cout << "[‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦]" << std::endl;
		std::cout << "•\Ž¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

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
		std::cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << std::endl;
		std::cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << std::endl;
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