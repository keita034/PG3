#include "TaskDataControl.h"
#include"UserDataList.h"

#include<filesystem>
#include<iostream>

TaskDataControl::TaskDataControl(TaskDataList* taskList, UserDataList* userList)
{
	taskDataList = taskList;
	userDataList = userList;
}

TaskDataControl::~TaskDataControl()
{
}

void TaskDataControl::Edit()
{
	//���O
	std::string user;
	TaskData* data;

	std::cout << "[�^�X�N�ҏW]" << std::endl;

	std::cout << "���O��ID����͂��Ă�������" << std::endl;
	std::cout << std::endl;

	std::cin >> user;
	std::cout << std::endl;

	data = taskDataList->GetData(user);

	if (!data)
	{
		long id = std::atol(user.c_str());

		data = taskDataList->GetData(id);
	}

	if (!data)
	{
		std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
		std::cout << std::endl;

	}
	else
	{
#pragma region �^�C�g��
		{
			std::cout << "�ύX����^�C�g������͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string title;
			while (std::getchar() != '\n');

			std::getline(std::cin, title);
			std::cout << std::endl;

			if (title != "")
			{
				std::cout << data->title.c_str() << "��" << title.c_str() << "�ɕύX����܂���" << std::endl;
				std::cout << std::endl;

				data->title = title;
			}
		}

#pragma endregion

#pragma region �S����

		{
			std::cout << "�ύX����S���҂���͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string user;
			USERDATA* userdata = nullptr;

			std::getline(std::cin, user);
			std::cout << std::endl;


			if (user != "")
			{
				while (!userdata)
				{
					userdata = userDataList->GetData(user);

					if (!userdata)
					{
						long id = std::atol(user.c_str());

						userdata = userDataList->GetData(id);

						if (!userdata)
						{
							std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
							std::cout << std::endl;

							std::cin >> user;
							std::cout << std::endl;
						}
					}

				}

				std::cout << data->pic.name.c_str() << "��" << userdata->name.c_str() << "�ɕύX����܂���" << std::endl;
				std::cout << std::endl;

				data->pic = *userdata;
			}
		}
#pragma endregion

#pragma region ���e

		{
			std::cout << "�ύX������e����͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string content;

			std::getline(std::cin, content);
			std::cout << std::endl;

			if (content != "")
			{
				std::cout << data->content.c_str() << "��" << content.c_str() << "�ɕύX����܂���" << std::endl;
				std::cout << std::endl;

				data->content = content;
			}
		}

#pragma endregion

#pragma region �D��x
		{
			std::cout << "�ύX����D��x����͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << "1:���}" << std::endl;
			std::cout << "2:����" << std::endl;
			std::cout << "3:�ʏ�" << std::endl;
			std::cout << "4:���" << std::endl;
			std::cout << std::endl;

			std::string numStr;

			std::getline(std::cin, numStr);
			std::cout << std::endl;

			if (numStr != "")
			{
				int num = atoi(numStr.c_str());

				PRIORITY priority;

				switch (num)
				{
				case 1:
					priority = PRIORITY::IMMEDIATELY;
					break;
				case 2:
					priority = PRIORITY::HIGHER;
					break;
				case 3:
					priority = PRIORITY::GENERALLY;
					break;
				case 4:
					priority = PRIORITY::LOWER;
					break;
				default:
					priority = PRIORITY::ERROR;
					break;
				}


				switch (static_cast<int>(data->priority))
				{
				case 0:
					std::cout << "���}";
					break;
				case 1:
					std::cout << "����";
					break;
				case 2:
					std::cout << "�ʏ�";
					break;
				case 3:
					std::cout << "���";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "��";

				switch (static_cast<int>(priority))
				{
				case 0:
					std::cout << "���}";
					break;
				case 1:
					std::cout << "����";
					break;
				case 2:
					std::cout << "�ʏ�";
					break;
				case 3:
					std::cout << "���";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "�ɕύX����܂���" << std::endl;

				std::cout << std::endl;

				data->priority = priority;
			}
		}

#pragma endregion

#pragma region �I���\�莞��

		std::cout << "�ύX����I���\�莞�Ԃ���͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
		std::cout << std::endl;

		std::string time;
		TIMEDATA endTime{};

		std::getline(std::cin, time);
		std::cout << std::endl;

		if (time != "")
		{

			std::istringstream stream(time);
			std::string str;

			getline(stream, str, '/');
			endTime.year = atoi(str.c_str());

			getline(stream, str, '/');
			endTime.month = atoi(str.c_str());

			getline(stream, str, '/');
			endTime.day = atoi(str.c_str());

			getline(stream, str, '/');
			endTime.hour = atoi(str.c_str());

			getline(stream, str, '/');
			endTime.min = atoi(str.c_str());

			endTime.sec = 0;
			endTime.msec = 0;

			getline(stream, str, '/');
			endTime.wday = atoi(str.c_str());

			std::cout<<data->endTime.year << '/' <<
				data->endTime.month << '/' <<
				data->endTime.day << '/' <<
				data->endTime.hour << '/' <<
				data->endTime.min << '/';
			switch (data->endTime.wday)
			{
			case 0:
				std::cout << "���j��";
				break;
			case 1:
				std::cout << "���j��";
				break;
			case 2:
				std::cout << "�Ηj��";
				break;
			case 3:
				std::cout << "���j��";
				break;
			case 4:
				std::cout << "�ؗj��";
				break;
			case 5:
				std::cout << "���j��";
				break;
			case 6:
				std::cout << "�y�j��";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "��"; 


			std::cout << endTime.year << '/' <<
			endTime.month << '/' <<
				endTime.day << '/' <<
				endTime.hour << '/' <<
				endTime.min << '/';
			switch (endTime.wday)
			{
			case 0:
				std::cout << "���j��";
				break;
			case 1:
				std::cout << "���j��";
				break;
			case 2:
				std::cout << "�Ηj��";
				break;
			case 3:
				std::cout << "���j��";
				break;
			case 4:
				std::cout << "�ؗj��";
				break;
			case 5:
				std::cout << "���j��";
				break;
			case 6:
				std::cout << "�y�j��";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "�ɕύX����܂���" << std::endl;
			std::cout << std::endl;

			data->endTime = endTime;
		}

#pragma endregion

#pragma region �X�e�[�^�X
		{
			std::cout << "�ύX����X�e�[�^�X����͂��Ă��������ύX���Ȃ��ꍇ�͉������͂��Ȃ��ł�������" << std::endl;
			std::cout << std::endl;

			std::string statusStr;

			std::getline(std::cin, statusStr);
			std::cout << std::endl;

			if (statusStr != "")
			{
				int num = atoi(statusStr.c_str());

				STATUS status;

				switch (num)
				{
				case 1:
					status = STATUS::NEW;
					break;
				case 2:
					status = STATUS::WORKING;
					break;
				case 3:
					status = STATUS::WAITING;
					break;
				case 4:
					status = STATUS::COMPLETED;
					break;
				case 6:
					status = STATUS::DISCONTINUED;
					break;
				case 7:
					status = STATUS::PENDING;
					break;
				default:
					status = STATUS::ERROR;
					break;
				}

				switch (static_cast<int>(data->status))
				{
				case 0:
					std::cout << "�V�K";
					break;
				case 1:
					std::cout << "����";
					break;
				case 2:
					std::cout << "������";
					break;
				case 3:
					std::cout << "����";
					break;
				case 4:
					std::cout << "���~";
					break;
				case 5:
					std::cout << "�ۗ�";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "��";
				
				switch (static_cast<int>(status))
				{
				case 0:
					std::cout << "�V�K";
					break;
				case 1:
					std::cout << "����";
					break;
				case 2:
					std::cout << "������";
					break;
				case 3:
					std::cout << "����";
					break;
				case 4:
					std::cout << "���~";
					break;
				case 5:
					std::cout << "�ۗ�";
					break;
				default:
					std::cout << "ERROR";
					break;
				}
				
				std::cout << "�ɕύX����܂���" << std::endl;

				std::cout << std::endl;

				data->status = status;
			}
		}

#pragma endregion

	}

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Add()
{
	TaskData taskData;

	std::cout << "[�^�X�N�ǉ�]" << std::endl;

#pragma region �^�C�g��
	{

		std::cout << "�^�C�g������͂��Ă�������" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.title;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region �S����
	{
		USERDATA* userdata = nullptr;
		std::string user;

		std::cout << "�S���҂�ID�����O����͂��Ă�������" << std::endl;
		std::cout << std::endl;

		while (!userdata)
		{
			std::cin >> user;
			std::cout << std::endl;

			userdata = userDataList->GetData(user);

			if (!userdata)
			{
				long id = std::atol(user.c_str());

				userdata = userDataList->GetData(id);

				if (!userdata)
				{
					std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
					std::cout << std::endl;
				}
			}

		}

		taskData.pic = *userdata;
	}
#pragma endregion

#pragma region ���e
	{
		std::cout << "���e����͂��Ă�������" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.content;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region �D��x
	{
		int num;

		std::cout << "�D��x��I��ł�������" << std::endl;
		std::cout << "1:���}" << std::endl;
		std::cout << "2:����" << std::endl;
		std::cout << "3:�ʏ�" << std::endl;
		std::cout << "4:���" << std::endl;
		std::cout << std::endl;

		std::cin >> num;

		switch (num)
		{
		case 1:
			taskData.priority = PRIORITY::IMMEDIATELY;
			break;
		case 2:
			taskData.priority = PRIORITY::HIGHER;
			break;
		case 3:
			taskData.priority = PRIORITY::GENERALLY;
			break;
		case 4:
			taskData.priority = PRIORITY::LOWER;
			break;
		default:
			taskData.priority = PRIORITY::ERROR;
			break;
		}

		std::cout << std::endl;
	}
#pragma endregion

#pragma region �I���\�莞��
	{
		std::string time;

		std::cout << "/��؂�ŏI����������͂��Ă�������" << std::endl;
		std::cout << "��:�N/���i1�`12�j/���i1�`31�j/���i0�`23�j/���i0�`59�j/�j���i0:���j�`6:�y�j�j" << std::endl;
		std::cout << std::endl;

		std::cin >> time;

		std::istringstream stream(time);
		std::string str;

		getline(stream, str, '/');
		taskData.endTime.year = atoi(str.c_str());

		getline(stream, str, '/');
		taskData.endTime.month = atoi(str.c_str());

		getline(stream, str, '/');
		taskData.endTime.day = atoi(str.c_str());

		getline(stream, str, '/');
		taskData.endTime.hour = atoi(str.c_str());

		getline(stream, str, '/');
		taskData.endTime.min = atoi(str.c_str());

		taskData.endTime.sec = 0;
		taskData.endTime.msec = 0;

		getline(stream, str, '/');
		taskData.endTime.wday = atoi(str.c_str());
		std::cout << std::endl;


	}
#pragma endregion

#pragma region �X�e�[�^�X

	{
		int num;

		std::cout << "�X�e�[�^�X��I��ł�������" << std::endl;
		std::cout << "1:�V�K" << std::endl;
		std::cout << "2:����" << std::endl;
		std::cout << "3:������" << std::endl;
		std::cout << "4:����" << std::endl;
		std::cout << "5:���~" << std::endl;
		std::cout << "6:�ۗ�" << std::endl;
		std::cout << std::endl;

		std::cin >> num;

		switch (num)
		{
		case 1:
			taskData.status = STATUS::NEW;
			break;
		case 2:
			taskData.status = STATUS::WORKING;
			break;
		case 3:
			taskData.status = STATUS::WAITING;
			break;
		case 4:
			taskData.status = STATUS::COMPLETED;
			break;
		case 6:
			taskData.status = STATUS::DISCONTINUED;
			break;
		case 7:
			taskData.status = STATUS::PENDING;
			break;
		default:
			taskData.status = STATUS::ERROR;
			break;
		}

		std::cout << std::endl;
	}

#pragma endregion

	taskDataList->AddData(taskData);

#pragma region �`��

	std::cout << "ID:" << taskData.id << std::endl;
	std::cout << "�S����:" << taskData.pic.name << std::endl;
	std::cout << "�^�C�g��:" << taskData.title << std::endl;
	std::cout << "���e:" << taskData.content << std::endl;
	std::cout << "�D��x:";
	switch (static_cast<int>(taskData.priority))
	{
	case 0:
		std::cout << "���}" << std::endl;
		break;
	case 1:
		std::cout << "����" << std::endl;
		break;
	case 2:
		std::cout << "�ʏ�" << std::endl;
		break;
	case 3:
		std::cout << "���" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}

	std::cout << "�I���\�莞��:" <<
		taskData.endTime.year << '/' <<
		taskData.endTime.month << '/' <<
		taskData.endTime.day << '/' <<
		taskData.endTime.hour << '/' <<
		taskData.endTime.min << '/';
	switch (taskData.endTime.wday)
	{
	case 0:
		std::cout << "���j��";
		break;
	case 1:
		std::cout << "���j��";
		break;
	case 2:
		std::cout << "�Ηj��";
		break;
	case 3:
		std::cout << "���j��";
		break;
	case 4:
		std::cout << "�ؗj��";
		break;
	case 5:
		std::cout << "���j��";
		break;
	case 6:
		std::cout << "�y�j��";
		break;
	default:
		std::cout << "ERROR";
		break;
	}
	std::cout << std::endl;

	std::cout << "�X�e�[�^�X:";
	switch (static_cast<int>(taskData.status))
	{
	case 0:
		std::cout << "�V�K" << std::endl;
		break;
	case 1:
		std::cout << "����" << std::endl;
		break;
	case 2:
		std::cout << "������" << std::endl;
		break;
	case 3:
		std::cout << "����" << std::endl;
		break;
	case 4:
		std::cout << "���~" << std::endl;
		break;
	case 5:
		std::cout << "�ۗ�" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}
	std::cout << std::endl;

#pragma endregion

	std::cout << "���̏��Œǉ����܂���" << std::endl;
	std::cout << std::endl;

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Sub()
{
	std::string user;
	TaskData* data;

	std::cout << "[�^�X�N�폜]" << std::endl;

	std::cout << "���O��ID����͂��Ă�������" << std::endl;

	std::cout << std::endl;

	std::cin >> user;
	std::cout << std::endl;

	data = taskDataList->GetData(user);

	if (!data)
	{
		long id = std::atol(user.c_str());

		data = taskDataList->GetData(id);
	}

	if (!data)
	{
		std::cout << "���̖��O��ID�͑��݂��܂���" << std::endl;
		std::cout << std::endl;
	}
	else
	{
#pragma region �`��

		std::cout << "ID:" << data->id << std::endl;
		std::cout << "�S����:" << data->pic.name << std::endl;
		std::cout << "�^�C�g��:" << data->title << std::endl;
		std::cout << "���e:" << data->content << std::endl;
		std::cout << "�D��x:";
		switch (static_cast<int>(data->priority))
		{
		case 0:
			std::cout << "���}" << std::endl;
			break;
		case 1:
			std::cout << "����" << std::endl;
			break;
		case 2:
			std::cout << "�ʏ�" << std::endl;
			break;
		case 3:
			std::cout << "���" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}

		std::cout << "�I���\�莞��:" <<
			data->endTime.year << '/' <<
			data->endTime.month << '/' <<
			data->endTime.day << '/' <<
			data->endTime.hour << '/' <<
			data->endTime.min << '/';
		switch (data->endTime.wday)
		{
		case 0:
			std::cout << "���j��";
			break;
		case 1:
			std::cout << "���j��";
			break;
		case 2:
			std::cout << "�Ηj��";
			break;
		case 3:
			std::cout << "���j��";
			break;
		case 4:
			std::cout << "�ؗj��";
			break;
		case 5:
			std::cout << "���j��";
			break;
		case 6:
			std::cout << "�y�j��";
			break;
		default:
			std::cout << "ERROR";
			break;
		}
		std::cout << std::endl;

		std::cout << "�X�e�[�^�X:";
		switch (static_cast<int>(data->status))
		{
		case 0:
			std::cout << "�V�K" << std::endl;
			break;
		case 1:
			std::cout << "����" << std::endl;
			break;
		case 2:
			std::cout << "������" << std::endl;
			break;
		case 3:
			std::cout << "����" << std::endl;
			break;
		case 4:
			std::cout << "���~" << std::endl;
			break;
		case 5:
			std::cout << "�ۗ�" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}
		std::cout << std::endl;
#pragma endregion

		std::cout << "���̃^�X�N���폜���܂���" << std::endl;
		std::cout << std::endl;

		long id = data->id;

		taskDataList->SubData(id);
	}

	std::cout << "�߂�ɂ͔C�ӂ̃L�[�������Ă�������" << std::endl;

	GetEnter();

	system("cls");
}
