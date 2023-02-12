#pragma once
#include<unordered_map>

#include"Constant.h"

class TaskDataList
{
public:
	TaskDataList();
	~TaskDataList() = default;

	/// <summary>
	/// ファイルからせーたを読み込み
	/// </summary>
	/// <param name="path">ファイルパス</param>
	void ReadData(const std::string& path);

	/// <summary>
	/// データを追加
	/// </summary>
	/// <param name="data">ユーザーデータ</param>
	void AddData(TaskData& data);

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
	TaskData* GetData(long id);

	/// <summary>
	/// データを取得
	/// </summary>
	/// <param name="name">ユーザー名前</param>
	/// <returns>ユーザーデータ</returns>
	TaskData* GetData(const std::string& name);

private:

	std::unordered_map<long, TaskData> list;
};

