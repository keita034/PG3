#include "UserDataControl.h"

#include<iostream>

UserDataControl::UserDataControl(UserDataList* list)
{
	userDataList = list;
}

UserDataControl::~UserDataControl()
{
}

void UserDataControl::Edit()
{
	//名前
	std::string user;
	USERDATA* data;

	std::cout << "[担当者編集]" << std::endl;

	std::cout << "名前かIDを入力してください" << std::endl;
	std::cout << std::endl;

	std::cin >> user;
	std::cout << std::endl;

	data = userDataList->GetData(user);

	if (!data)
	{
		long id = std::atol(user.c_str());

		data = userDataList->GetData(id);
	}

	if (!data)
	{
		std::cout << "この名前かIDは存在しません" << std::endl;
		std::cout << std::endl;

	}
	else
	{
		{
			std::cout << "変更する名前を入力してください変更しない場合は何も入力しないでください" << std::endl;
			std::cout << std::endl;

			std::string name;
			while (std::getchar() != '\n');

			std::getline(std::cin, name);
			std::cout << std::endl;

			if (name != "")
			{
				std::cout << data->name.c_str() << "が" << name.c_str() << "に変更されました" << std::endl;
				std::cout << std::endl;

				data->name = name;
			}
		}

		{
			std::cout << "変更する所属を入力してください変更しない場合は何も入力しないでください" << std::endl;
			std::cout << std::endl;

			std::string affiliation;
			std::getline(std::cin, affiliation);

			if (affiliation != "")
			{
				std::cout << data->affiliation.c_str() << "が" << affiliation.c_str() << "に変更されました" << std::endl;
				std::cout << std::endl;

				data->affiliation = affiliation;
			}
		}

	}

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");
}

void UserDataControl::Add()
{

	//名前
	std::string name;
	//所属
	std::string affiliation;

	std::cout << "[担当者追加]" << std::endl;
	std::cout << "名前を入力してください" << std::endl;
	std::cout << std::endl;

	std::cin >> name;
	std::cout << std::endl;

	std::cout << "所属を入力してください" << std::endl;
	std::cout << std::endl;

	std::cin >> affiliation;
	std::cout << std::endl;

	USERDATA data = USERDATA(name, affiliation);

	userDataList->AddData(data);

	std::cout << "名前:" << data.name.c_str() << std::endl;
	std::cout << "所属:" << data.affiliation.c_str() << std::endl;
	std::cout << "ID:" << data.id << std::endl;
	std::cout << std::endl;

	std::cout << "この情報で追加しました" << std::endl;
	std::cout << std::endl;

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");

}

void UserDataControl::Sub()
{
	std::string user;
	USERDATA* data;

	std::cout << "[担当者編集]" << std::endl;

	std::cout << "名前かIDを入力してください" << std::endl;

	std::cout << std::endl;

	std::cin >> user;
	std::cout << std::endl;

	data = userDataList->GetData(user);

	if (!data)
	{
		long id = std::atol(user.c_str());

		data = userDataList->GetData(id);
	}

	if (!data)
	{
		std::cout << "この名前かIDは存在しません" << std::endl;
		std::cout << std::endl;
	}
	else
	{

		std::cout << "名前:" << data->name.c_str() << std::endl;
		std::cout << "所属:" << data->affiliation.c_str() << std::endl;
		std::cout << "ID:" << data->id << std::endl;
		std::cout << std::endl;

		std::cout << "このユーザーを削除しました" << std::endl;
		std::cout << std::endl;

		long id = data->id;
		userDataList->SubData(id);
	}

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");
}

