#include "TaskDataList.h"

TaskDataList::TaskDataList()
{
}

void TaskDataList::ReadData(const std::string& path)
{
}

void TaskDataList::AddData(TaskData& data)
{
	std::conditional<false,
		std::list<std::pair<const long, TaskData>,
		std::allocator<std::pair<const long, TaskData>>>::const_iterator,
		std::list<std::pair<const long, TaskData>,
		std::allocator<std::pair<const long, TaskData>>>::iterator>::type itr = list.end();

	while (itr == list.end())
	{
		data.id = GetRand(10000, 99999);

		itr = std::find_if(list.begin(), list.end(), [&](std::pair<const long, TaskData> p)
			{
				return p.second.id == data.id;
			});

		if (itr == list.end())
		{
			//�ǉ�
			list.insert(std::make_pair(data.id, data));

			return;
		}
	}

}

void TaskDataList::SubData(long id)
{
	//�폜
	list.erase(id);
}

void TaskDataList::ClearData()
{
	//�N���A
	list.clear();
}

TaskData* TaskDataList::GetData(long id)
{
	auto itr = std::find_if(list.begin(), list.end(), [&id](std::pair<const long, TaskData> p)
		{
			return p.second.id == id;
		});

	if (itr != list.end())
	{
		//���������̂ŕԂ�
		return &itr._Ptr->_Myval.second;
	}

	//������Ȃ��̂ŃG���[
	return nullptr;
}

TaskData* TaskDataList::GetData(const std::string& name)
{
	auto itr = std::find_if(list.begin(), list.end(), [&name](std::pair<const long, TaskData> p)
		{
			return p.second.title == name;
		});

	if (itr != list.end())
	{
		//���������̂ŕԂ�
		return &itr._Ptr->_Myval.second;
	}

	//������Ȃ��̂ŃG���[
	return nullptr;
}
