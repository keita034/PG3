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
	//ñºëO
	std::string user;
	TaskData* data;

	std::cout << "[É^ÉXÉNï“èW]" << std::endl;

	std::cout << "ñºëOÇ©IDÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;
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
		std::cout << "Ç±ÇÃñºëOÇ©IDÇÕë∂ç›ÇµÇ‹ÇπÇÒ" << std::endl;
		std::cout << std::endl;

	}
	else
	{
#pragma region É^ÉCÉgÉã
		{
			std::cout << "ïœçXÇ∑ÇÈÉ^ÉCÉgÉãÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
			std::cout << std::endl;

			std::string title;
			while (std::getchar() != '\n');

			std::getline(std::cin, title);
			std::cout << std::endl;

			if (title != "")
			{
				std::cout << data->title.c_str() << "Ç™" << title.c_str() << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;
				std::cout << std::endl;

				data->title = title;
			}
		}

#pragma endregion

#pragma region íSìñé“

		{
			std::cout << "ïœçXÇ∑ÇÈíSìñé“Çì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
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
							std::cout << "Ç±ÇÃñºëOÇ©IDÇÕë∂ç›ÇµÇ‹ÇπÇÒ" << std::endl;
							std::cout << std::endl;

							std::cin >> user;
							std::cout << std::endl;
						}
					}

				}

				std::cout << data->pic.name.c_str() << "Ç™" << userdata->name.c_str() << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;
				std::cout << std::endl;

				data->pic = *userdata;
			}
		}
#pragma endregion

#pragma region ì‡óe

		{
			std::cout << "ïœçXÇ∑ÇÈì‡óeÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
			std::cout << std::endl;

			std::string content;

			std::getline(std::cin, content);
			std::cout << std::endl;

			if (content != "")
			{
				std::cout << data->content.c_str() << "Ç™" << content.c_str() << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;
				std::cout << std::endl;

				data->content = content;
			}
		}

#pragma endregion

#pragma region óDêÊìx
		{
			std::cout << "ïœçXÇ∑ÇÈóDêÊìxÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
			std::cout << "1:ëÅã}" << std::endl;
			std::cout << "2:çÇÇﬂ" << std::endl;
			std::cout << "3:í èÌ" << std::endl;
			std::cout << "4:í·Çﬂ" << std::endl;
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
					std::cout << "ëÅã}";
					break;
				case 1:
					std::cout << "çÇÇﬂ";
					break;
				case 2:
					std::cout << "í èÌ";
					break;
				case 3:
					std::cout << "í·Çﬂ";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "Ç™";

				switch (static_cast<int>(priority))
				{
				case 0:
					std::cout << "ëÅã}";
					break;
				case 1:
					std::cout << "çÇÇﬂ";
					break;
				case 2:
					std::cout << "í èÌ";
					break;
				case 3:
					std::cout << "í·Çﬂ";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;

				std::cout << std::endl;

				data->priority = priority;
			}
		}

#pragma endregion

#pragma region èIóπó\íËéûä‘

		std::cout << "ïœçXÇ∑ÇÈèIóπó\íËéûä‘Çì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
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
				std::cout << "ì˙ójì˙";
				break;
			case 1:
				std::cout << "åéójì˙";
				break;
			case 2:
				std::cout << "âŒójì˙";
				break;
			case 3:
				std::cout << "êÖójì˙";
				break;
			case 4:
				std::cout << "ñÿójì˙";
				break;
			case 5:
				std::cout << "ã‡ójì˙";
				break;
			case 6:
				std::cout << "ìyójì˙";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "Ç™"; 


			std::cout << endTime.year << '/' <<
			endTime.month << '/' <<
				endTime.day << '/' <<
				endTime.hour << '/' <<
				endTime.min << '/';
			switch (endTime.wday)
			{
			case 0:
				std::cout << "ì˙ójì˙";
				break;
			case 1:
				std::cout << "åéójì˙";
				break;
			case 2:
				std::cout << "âŒójì˙";
				break;
			case 3:
				std::cout << "êÖójì˙";
				break;
			case 4:
				std::cout << "ñÿójì˙";
				break;
			case 5:
				std::cout << "ã‡ójì˙";
				break;
			case 6:
				std::cout << "ìyójì˙";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;
			std::cout << std::endl;

			data->endTime = endTime;
		}

#pragma endregion

#pragma region ÉXÉeÅ[É^ÉX
		{
			std::cout << "ïœçXÇ∑ÇÈÉXÉeÅ[É^ÉXÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ïœçXÇµÇ»Ç¢èÍçáÇÕâΩÇ‡ì¸óÕÇµÇ»Ç¢Ç≈Ç≠ÇæÇ≥Ç¢" << std::endl;
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
					std::cout << "êVãK";
					break;
				case 1:
					std::cout << "íÖéË";
					break;
				case 2:
					std::cout << "ñ¢íÖéË";
					break;
				case 3:
					std::cout << "äÆóπ";
					break;
				case 4:
					std::cout << "íÜé~";
					break;
				case 5:
					std::cout << "ï€óØ";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "Ç™";
				
				switch (static_cast<int>(status))
				{
				case 0:
					std::cout << "êVãK";
					break;
				case 1:
					std::cout << "íÖéË";
					break;
				case 2:
					std::cout << "ñ¢íÖéË";
					break;
				case 3:
					std::cout << "äÆóπ";
					break;
				case 4:
					std::cout << "íÜé~";
					break;
				case 5:
					std::cout << "ï€óØ";
					break;
				default:
					std::cout << "ERROR";
					break;
				}
				
				std::cout << "Ç…ïœçXÇ≥ÇÍÇ‹ÇµÇΩ" << std::endl;

				std::cout << std::endl;

				data->status = status;
			}
		}

#pragma endregion

	}

	std::cout << "ñﬂÇÈÇ…ÇÕîCà”ÇÃÉLÅ[ÇâüÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Add()
{
	TaskData taskData;

	std::cout << "[É^ÉXÉNí«â¡]" << std::endl;

#pragma region É^ÉCÉgÉã
	{

		std::cout << "É^ÉCÉgÉãÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.title;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region íSìñé“
	{
		USERDATA* userdata = nullptr;
		std::string user;

		std::cout << "íSìñé“ÇÃIDÇ©ñºëOÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;
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
					std::cout << "Ç±ÇÃñºëOÇ©IDÇÕë∂ç›ÇµÇ‹ÇπÇÒ" << std::endl;
					std::cout << std::endl;
				}
			}

		}

		taskData.pic = *userdata;
	}
#pragma endregion

#pragma region ì‡óe
	{
		std::cout << "ì‡óeÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.content;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region óDêÊìx
	{
		int num;

		std::cout << "óDêÊìxÇëIÇÒÇ≈Ç≠ÇæÇ≥Ç¢" << std::endl;
		std::cout << "1:ëÅã}" << std::endl;
		std::cout << "2:çÇÇﬂ" << std::endl;
		std::cout << "3:í èÌ" << std::endl;
		std::cout << "4:í·Çﬂ" << std::endl;
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

#pragma region èIóπó\íËéûä‘
	{
		std::string time;

		std::cout << "/ãÊêÿÇËÇ≈èIóπéûçèÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;
		std::cout << "ó·:îN/åéÅi1Å`12Åj/ì˙Åi1Å`31Åj/éûÅi0Å`23Åj/ï™Åi0Å`59Åj/ójì˙Åi0:ì˙ójÅ`6:ìyójÅj" << std::endl;
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

#pragma region ÉXÉeÅ[É^ÉX

	{
		int num;

		std::cout << "ÉXÉeÅ[É^ÉXÇëIÇÒÇ≈Ç≠ÇæÇ≥Ç¢" << std::endl;
		std::cout << "1:êVãK" << std::endl;
		std::cout << "2:íÖéË" << std::endl;
		std::cout << "3:ñ¢íÖéË" << std::endl;
		std::cout << "4:äÆóπ" << std::endl;
		std::cout << "5:íÜé~" << std::endl;
		std::cout << "6:ï€óØ" << std::endl;
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

#pragma region ï`âÊ

	std::cout << "ID:" << taskData.id << std::endl;
	std::cout << "íSìñé“:" << taskData.pic.name << std::endl;
	std::cout << "É^ÉCÉgÉã:" << taskData.title << std::endl;
	std::cout << "ì‡óe:" << taskData.content << std::endl;
	std::cout << "óDêÊìx:";
	switch (static_cast<int>(taskData.priority))
	{
	case 0:
		std::cout << "ëÅã}" << std::endl;
		break;
	case 1:
		std::cout << "çÇÇﬂ" << std::endl;
		break;
	case 2:
		std::cout << "í èÌ" << std::endl;
		break;
	case 3:
		std::cout << "í·Çﬂ" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}

	std::cout << "èIóπó\íËéûä‘:" <<
		taskData.endTime.year << '/' <<
		taskData.endTime.month << '/' <<
		taskData.endTime.day << '/' <<
		taskData.endTime.hour << '/' <<
		taskData.endTime.min << '/';
	switch (taskData.endTime.wday)
	{
	case 0:
		std::cout << "ì˙ójì˙";
		break;
	case 1:
		std::cout << "åéójì˙";
		break;
	case 2:
		std::cout << "âŒójì˙";
		break;
	case 3:
		std::cout << "êÖójì˙";
		break;
	case 4:
		std::cout << "ñÿójì˙";
		break;
	case 5:
		std::cout << "ã‡ójì˙";
		break;
	case 6:
		std::cout << "ìyójì˙";
		break;
	default:
		std::cout << "ERROR";
		break;
	}
	std::cout << std::endl;

	std::cout << "ÉXÉeÅ[É^ÉX:";
	switch (static_cast<int>(taskData.status))
	{
	case 0:
		std::cout << "êVãK" << std::endl;
		break;
	case 1:
		std::cout << "íÖéË" << std::endl;
		break;
	case 2:
		std::cout << "ñ¢íÖéË" << std::endl;
		break;
	case 3:
		std::cout << "äÆóπ" << std::endl;
		break;
	case 4:
		std::cout << "íÜé~" << std::endl;
		break;
	case 5:
		std::cout << "ï€óØ" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}
	std::cout << std::endl;

#pragma endregion

	std::cout << "Ç±ÇÃèÓïÒÇ≈í«â¡ÇµÇ‹ÇµÇΩ" << std::endl;
	std::cout << std::endl;

	std::cout << "ñﬂÇÈÇ…ÇÕîCà”ÇÃÉLÅ[ÇâüÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Sub()
{
	std::string user;
	TaskData* data;

	std::cout << "[É^ÉXÉNçÌèú]" << std::endl;

	std::cout << "ñºëOÇ©IDÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;

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
		std::cout << "Ç±ÇÃñºëOÇ©IDÇÕë∂ç›ÇµÇ‹ÇπÇÒ" << std::endl;
		std::cout << std::endl;
	}
	else
	{
#pragma region ï`âÊ

		std::cout << "ID:" << data->id << std::endl;
		std::cout << "íSìñé“:" << data->pic.name << std::endl;
		std::cout << "É^ÉCÉgÉã:" << data->title << std::endl;
		std::cout << "ì‡óe:" << data->content << std::endl;
		std::cout << "óDêÊìx:";
		switch (static_cast<int>(data->priority))
		{
		case 0:
			std::cout << "ëÅã}" << std::endl;
			break;
		case 1:
			std::cout << "çÇÇﬂ" << std::endl;
			break;
		case 2:
			std::cout << "í èÌ" << std::endl;
			break;
		case 3:
			std::cout << "í·Çﬂ" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}

		std::cout << "èIóπó\íËéûä‘:" <<
			data->endTime.year << '/' <<
			data->endTime.month << '/' <<
			data->endTime.day << '/' <<
			data->endTime.hour << '/' <<
			data->endTime.min << '/';
		switch (data->endTime.wday)
		{
		case 0:
			std::cout << "ì˙ójì˙";
			break;
		case 1:
			std::cout << "åéójì˙";
			break;
		case 2:
			std::cout << "âŒójì˙";
			break;
		case 3:
			std::cout << "êÖójì˙";
			break;
		case 4:
			std::cout << "ñÿójì˙";
			break;
		case 5:
			std::cout << "ã‡ójì˙";
			break;
		case 6:
			std::cout << "ìyójì˙";
			break;
		default:
			std::cout << "ERROR";
			break;
		}
		std::cout << std::endl;

		std::cout << "ÉXÉeÅ[É^ÉX:";
		switch (static_cast<int>(data->status))
		{
		case 0:
			std::cout << "êVãK" << std::endl;
			break;
		case 1:
			std::cout << "íÖéË" << std::endl;
			break;
		case 2:
			std::cout << "ñ¢íÖéË" << std::endl;
			break;
		case 3:
			std::cout << "äÆóπ" << std::endl;
			break;
		case 4:
			std::cout << "íÜé~" << std::endl;
			break;
		case 5:
			std::cout << "ï€óØ" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}
		std::cout << std::endl;
#pragma endregion

		std::cout << "Ç±ÇÃÉ^ÉXÉNÇçÌèúÇµÇ‹ÇµÇΩ" << std::endl;
		std::cout << std::endl;

		long id = data->id;

		taskDataList->SubData(id);
	}

	std::cout << "ñﬂÇÈÇ…ÇÕîCà”ÇÃÉLÅ[ÇâüÇµÇƒÇ≠ÇæÇ≥Ç¢" << std::endl;

	GetEnter();

	system("cls");
}
