#include "UserDataList.h"

UserDataList::UserDataList()
{
}

void UserDataList::ReadData(const std::string& path)
{
}

void UserDataList::AddData(USERDATA& data)
{
	std::conditional<false,
		std::list<std::pair<const long, USERDATA>,
		std::allocator<std::pair<const long, USERDATA>>>::const_iterator,
		std::list<std::pair<const long, USERDATA>,
		std::allocator<std::pair<const long, USERDATA>>>::iterator>::type itr = list.end();

	while (itr == list.end())
	{
		data.id = GetRand(10000, 99999);

		itr = std::find_if(list.begin(), list.end(), [&](std::pair<const long, USERDATA> p)
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

void UserDataList::SubData(long id)
{
	//�폜
	list.erase(id);
}

void UserDataList::ClearData()
{
	//�N���A
	list.clear();
}

USERDATA* UserDataList::GetData(long id)
{
	auto itr = std::find_if(list.begin(), list.end(), [&id](std::pair<const long, USERDATA> p)
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

USERDATA* UserDataList::GetData(const std::string& name)
{
	auto itr = std::find_if(list.begin(), list.end(), [&name](std::pair<const long, USERDATA> p)
		{
			return p.second.name == name;
		});

	if (itr != list.end())
	{
		//���������̂ŕԂ�
		return &itr._Ptr->_Myval.second;
	}

	//������Ȃ��̂ŃG���[
	return nullptr;
}
