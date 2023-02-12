#pragma once
#include"UserDataList.h"
#include"BaseDataControl.h"
class UserDataControl :public BaseDataControl
{
public:

	UserDataControl(UserDataList* list);
	~UserDataControl();

	void Edit()override;

	void Add()override;

	void Sub()override;

private:

	UserDataList* userDataList;
};

