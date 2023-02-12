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
	//名前
	std::string user;
	TaskData* data;

	std::cout << "[タスク編集]" << std::endl;

	std::cout << "名前かIDを入力してください" << std::endl;
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
		std::cout << "この名前かIDは存在しません" << std::endl;
		std::cout << std::endl;

	}
	else
	{
#pragma region タイトル
		{
			std::cout << "変更するタイトルを入力してください変更しない場合は何も入力しないでください" << std::endl;
			std::cout << std::endl;

			std::string title;
			while (std::getchar() != '\n');

			std::getline(std::cin, title);
			std::cout << std::endl;

			if (title != "")
			{
				std::cout << data->title.c_str() << "が" << title.c_str() << "に変更されました" << std::endl;
				std::cout << std::endl;

				data->title = title;
			}
		}

#pragma endregion

#pragma region 担当者

		{
			std::cout << "変更する担当者を入力してください変更しない場合は何も入力しないでください" << std::endl;
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
							std::cout << "この名前かIDは存在しません" << std::endl;
							std::cout << std::endl;

							std::cin >> user;
							std::cout << std::endl;
						}
					}

				}

				std::cout << data->pic.name.c_str() << "が" << userdata->name.c_str() << "に変更されました" << std::endl;
				std::cout << std::endl;

				data->pic = *userdata;
			}
		}
#pragma endregion

#pragma region 内容

		{
			std::cout << "変更する内容を入力してください変更しない場合は何も入力しないでください" << std::endl;
			std::cout << std::endl;

			std::string content;

			std::getline(std::cin, content);
			std::cout << std::endl;

			if (content != "")
			{
				std::cout << data->content.c_str() << "が" << content.c_str() << "に変更されました" << std::endl;
				std::cout << std::endl;

				data->content = content;
			}
		}

#pragma endregion

#pragma region 優先度
		{
			std::cout << "変更する優先度を入力してください変更しない場合は何も入力しないでください" << std::endl;
			std::cout << "1:早急" << std::endl;
			std::cout << "2:高め" << std::endl;
			std::cout << "3:通常" << std::endl;
			std::cout << "4:低め" << std::endl;
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
					std::cout << "早急";
					break;
				case 1:
					std::cout << "高め";
					break;
				case 2:
					std::cout << "通常";
					break;
				case 3:
					std::cout << "低め";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "が";

				switch (static_cast<int>(priority))
				{
				case 0:
					std::cout << "早急";
					break;
				case 1:
					std::cout << "高め";
					break;
				case 2:
					std::cout << "通常";
					break;
				case 3:
					std::cout << "低め";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "に変更されました" << std::endl;

				std::cout << std::endl;

				data->priority = priority;
			}
		}

#pragma endregion

#pragma region 終了予定時間

		std::cout << "変更する終了予定時間を入力してください変更しない場合は何も入力しないでください" << std::endl;
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
				std::cout << "日曜日";
				break;
			case 1:
				std::cout << "月曜日";
				break;
			case 2:
				std::cout << "火曜日";
				break;
			case 3:
				std::cout << "水曜日";
				break;
			case 4:
				std::cout << "木曜日";
				break;
			case 5:
				std::cout << "金曜日";
				break;
			case 6:
				std::cout << "土曜日";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "が"; 


			std::cout << endTime.year << '/' <<
			endTime.month << '/' <<
				endTime.day << '/' <<
				endTime.hour << '/' <<
				endTime.min << '/';
			switch (endTime.wday)
			{
			case 0:
				std::cout << "日曜日";
				break;
			case 1:
				std::cout << "月曜日";
				break;
			case 2:
				std::cout << "火曜日";
				break;
			case 3:
				std::cout << "水曜日";
				break;
			case 4:
				std::cout << "木曜日";
				break;
			case 5:
				std::cout << "金曜日";
				break;
			case 6:
				std::cout << "土曜日";
				break;
			default:
				std::cout << "ERROR";
				break;
			}

			std::cout << "に変更されました" << std::endl;
			std::cout << std::endl;

			data->endTime = endTime;
		}

#pragma endregion

#pragma region ステータス
		{
			std::cout << "変更するステータスを入力してください変更しない場合は何も入力しないでください" << std::endl;
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
					std::cout << "新規";
					break;
				case 1:
					std::cout << "着手";
					break;
				case 2:
					std::cout << "未着手";
					break;
				case 3:
					std::cout << "完了";
					break;
				case 4:
					std::cout << "中止";
					break;
				case 5:
					std::cout << "保留";
					break;
				default:
					std::cout << "ERROR";
					break;
				}

				std::cout << "が";
				
				switch (static_cast<int>(status))
				{
				case 0:
					std::cout << "新規";
					break;
				case 1:
					std::cout << "着手";
					break;
				case 2:
					std::cout << "未着手";
					break;
				case 3:
					std::cout << "完了";
					break;
				case 4:
					std::cout << "中止";
					break;
				case 5:
					std::cout << "保留";
					break;
				default:
					std::cout << "ERROR";
					break;
				}
				
				std::cout << "に変更されました" << std::endl;

				std::cout << std::endl;

				data->status = status;
			}
		}

#pragma endregion

	}

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Add()
{
	TaskData taskData;

	std::cout << "[タスク追加]" << std::endl;

#pragma region タイトル
	{

		std::cout << "タイトルを入力してください" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.title;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region 担当者
	{
		USERDATA* userdata = nullptr;
		std::string user;

		std::cout << "担当者のIDか名前を入力してください" << std::endl;
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
					std::cout << "この名前かIDは存在しません" << std::endl;
					std::cout << std::endl;
				}
			}

		}

		taskData.pic = *userdata;
	}
#pragma endregion

#pragma region 内容
	{
		std::cout << "内容を入力してください" << std::endl;
		std::cout << std::endl;

		std::cin >> taskData.content;
		std::cout << std::endl;
	}
#pragma endregion

#pragma region 優先度
	{
		int num;

		std::cout << "優先度を選んでください" << std::endl;
		std::cout << "1:早急" << std::endl;
		std::cout << "2:高め" << std::endl;
		std::cout << "3:通常" << std::endl;
		std::cout << "4:低め" << std::endl;
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

#pragma region 終了予定時間
	{
		std::string time;

		std::cout << "/区切りで終了時刻を入力してください" << std::endl;
		std::cout << "例:年/月（1〜12）/日（1〜31）/時（0〜23）/分（0〜59）/曜日（0:日曜〜6:土曜）" << std::endl;
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

#pragma region ステータス

	{
		int num;

		std::cout << "ステータスを選んでください" << std::endl;
		std::cout << "1:新規" << std::endl;
		std::cout << "2:着手" << std::endl;
		std::cout << "3:未着手" << std::endl;
		std::cout << "4:完了" << std::endl;
		std::cout << "5:中止" << std::endl;
		std::cout << "6:保留" << std::endl;
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

#pragma region 描画

	std::cout << "ID:" << taskData.id << std::endl;
	std::cout << "担当者:" << taskData.pic.name << std::endl;
	std::cout << "タイトル:" << taskData.title << std::endl;
	std::cout << "内容:" << taskData.content << std::endl;
	std::cout << "優先度:";
	switch (static_cast<int>(taskData.priority))
	{
	case 0:
		std::cout << "早急" << std::endl;
		break;
	case 1:
		std::cout << "高め" << std::endl;
		break;
	case 2:
		std::cout << "通常" << std::endl;
		break;
	case 3:
		std::cout << "低め" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}

	std::cout << "終了予定時間:" <<
		taskData.endTime.year << '/' <<
		taskData.endTime.month << '/' <<
		taskData.endTime.day << '/' <<
		taskData.endTime.hour << '/' <<
		taskData.endTime.min << '/';
	switch (taskData.endTime.wday)
	{
	case 0:
		std::cout << "日曜日";
		break;
	case 1:
		std::cout << "月曜日";
		break;
	case 2:
		std::cout << "火曜日";
		break;
	case 3:
		std::cout << "水曜日";
		break;
	case 4:
		std::cout << "木曜日";
		break;
	case 5:
		std::cout << "金曜日";
		break;
	case 6:
		std::cout << "土曜日";
		break;
	default:
		std::cout << "ERROR";
		break;
	}
	std::cout << std::endl;

	std::cout << "ステータス:";
	switch (static_cast<int>(taskData.status))
	{
	case 0:
		std::cout << "新規" << std::endl;
		break;
	case 1:
		std::cout << "着手" << std::endl;
		break;
	case 2:
		std::cout << "未着手" << std::endl;
		break;
	case 3:
		std::cout << "完了" << std::endl;
		break;
	case 4:
		std::cout << "中止" << std::endl;
		break;
	case 5:
		std::cout << "保留" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}
	std::cout << std::endl;

#pragma endregion

	std::cout << "この情報で追加しました" << std::endl;
	std::cout << std::endl;

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");
}

void TaskDataControl::Sub()
{
	std::string user;
	TaskData* data;

	std::cout << "[タスク削除]" << std::endl;

	std::cout << "名前かIDを入力してください" << std::endl;

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
		std::cout << "この名前かIDは存在しません" << std::endl;
		std::cout << std::endl;
	}
	else
	{
#pragma region 描画

		std::cout << "ID:" << data->id << std::endl;
		std::cout << "担当者:" << data->pic.name << std::endl;
		std::cout << "タイトル:" << data->title << std::endl;
		std::cout << "内容:" << data->content << std::endl;
		std::cout << "優先度:";
		switch (static_cast<int>(data->priority))
		{
		case 0:
			std::cout << "早急" << std::endl;
			break;
		case 1:
			std::cout << "高め" << std::endl;
			break;
		case 2:
			std::cout << "通常" << std::endl;
			break;
		case 3:
			std::cout << "低め" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}

		std::cout << "終了予定時間:" <<
			data->endTime.year << '/' <<
			data->endTime.month << '/' <<
			data->endTime.day << '/' <<
			data->endTime.hour << '/' <<
			data->endTime.min << '/';
		switch (data->endTime.wday)
		{
		case 0:
			std::cout << "日曜日";
			break;
		case 1:
			std::cout << "月曜日";
			break;
		case 2:
			std::cout << "火曜日";
			break;
		case 3:
			std::cout << "水曜日";
			break;
		case 4:
			std::cout << "木曜日";
			break;
		case 5:
			std::cout << "金曜日";
			break;
		case 6:
			std::cout << "土曜日";
			break;
		default:
			std::cout << "ERROR";
			break;
		}
		std::cout << std::endl;

		std::cout << "ステータス:";
		switch (static_cast<int>(data->status))
		{
		case 0:
			std::cout << "新規" << std::endl;
			break;
		case 1:
			std::cout << "着手" << std::endl;
			break;
		case 2:
			std::cout << "未着手" << std::endl;
			break;
		case 3:
			std::cout << "完了" << std::endl;
			break;
		case 4:
			std::cout << "中止" << std::endl;
			break;
		case 5:
			std::cout << "保留" << std::endl;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			break;
		}
		std::cout << std::endl;
#pragma endregion

		std::cout << "このタスクを削除しました" << std::endl;
		std::cout << std::endl;

		long id = data->id;

		taskDataList->SubData(id);
	}

	std::cout << "戻るには任意のキーを押してください" << std::endl;

	GetEnter();

	system("cls");
}
