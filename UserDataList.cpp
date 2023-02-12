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
			//追加
			list.insert(std::make_pair(data.id, data));

			return;
		}
	}

}

void UserDataList::SubData(long id)
{
	//削除
	list.erase(id);
}

void UserDataList::ClearData()
{
	//クリア
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
		//見つかったので返す
		return &itr._Ptr->_Myval.second;
	}

	//見つからないのでエラー
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
		//見つかったので返す
		return &itr._Ptr->_Myval.second;
	}

	//見つからないのでエラー
	return nullptr;
}
