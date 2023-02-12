#pragma once
#include<unordered_map>
#include<string>
#include<random>

#include"Constant.h"

class UserDataList
{
public:
	UserDataList();
	~UserDataList() = default;

	/// <summary>
	/// ファイルからせーたを読み込み
	/// </summary>
	/// <param name="path">ファイルパス</param>
	void ReadData(const std::string& path);

	/// <summary>
	/// データを追加
	/// </summary>
	/// <param name="data">ユーザーデータ</param>
	void AddData(USERDATA& data);

	/// <summary>
	/// データを削除
	/// </summary>
	/// <param name="id">ユーザーID</param>
	void SubData(long id);

	/// <summary>
	/// データをクリア
	/// </summary>
	void ClearData();

	/// <summary>
	/// データを取得
	/// </summary>
	/// <param name="id">ユーザーID</param>
	/// <returns>ユーザーデータ</returns>
	USERDATA* GetData(long id);

	/// <summary>
	/// データを取得
	/// </summary>
	/// <param name="name">ユーザー名前</param>
	/// <returns>ユーザーデータ</returns>
	USERDATA* GetData(const std::string& name);

private:

	std::unordered_map<long, USERDATA> list;

};

