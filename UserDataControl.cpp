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
	//���O
	std::string user;
	USERDATA* data;

	std::cout << "[�S���ҕҏW]" << std::endl;

	std::cout << "���O��ID����͂��Ă�������" << std::endl;
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
		std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
		std::cout << std::endl;

	}
	else
	{
		{
			std::cout << "�ύX���閼�O����͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string name;
			while (std::getchar() != '\n');

			std::getline(std::cin, name);
			std::cout << std::endl;

			if (name != "")
			{
				std::cout << data->name.c_str() << "��" << name.c_str() << "�ɕύX����܂���" << std::endl;
				std::cout << std::endl;

				data->name = name;
			}
		}

		{
			std::cout << "�ύX���鏊������͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string affiliation;
			std::getline(std::cin, affiliation);

			if (affiliation != "")
			{
				std::cout << data->affiliation.c_str() << "��" << affiliation.c_str() << "�ɕύX����܂���" << std::endl;
				std::cout << std::endl;

				data->affiliation = affiliation;
			}
		}

	}

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");
}

void UserDataControl::Add()
{

	//���O
	std::string name;
	//����
	std::string affiliation;

	std::cout << "[�S���Ғǉ�]" << std::endl;
	std::cout << "���O����͂��Ă�������" << std::endl;
	std::cout << std::endl;

	std::cin >> name;
	std::cout << std::endl;

	std::cout << "��������͂��Ă�������" << std::endl;
	std::cout << std::endl;

	std::cin >> affiliation;
	std::cout << std::endl;

	USERDATA data = USERDATA(name, affiliation);

	userDataList->AddData(data);

	std::cout << "���O:" << data.name.c_str() << std::endl;
	std::cout << "����:" << data.affiliation.c_str() << std::endl;
	std::cout << "ID:" << data.id << std::endl;
	std::cout << std::endl;

	std::cout << "���̏��Œǉ����܂���" << std::endl;
	std::cout << std::endl;

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");

}

void UserDataControl::Sub()
{
	std::string user;
	USERDATA* data;

	std::cout << "[�S���ҕҏW]" << std::endl;

	std::cout << "���O��ID����͂��Ă�������" << std::endl;

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
		std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
		std::cout << std::endl;
	}
	else
	{

		std::cout << "���O:" << data->name.c_str() << std::endl;
		std::cout << "����:" << data->affiliation.c_str() << std::endl;
		std::cout << "ID:" << data->id << std::endl;
		std::cout << std::endl;

		std::cout << "���̃��[�U�[���폜���܂���" << std::endl;
		std::cout << std::endl;

		long id = data->id;
		userDataList->SubData(id);
	}

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");
}

