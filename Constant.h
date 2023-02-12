#pragma once
#include<string>
#include<time.h>

//優先度
enum class PRIORITY
{
	IMMEDIATELY,	//早急
	HIGHER,			//高め
	GENERALLY,		//通常
	LOWER,			//低め
	ERROR
};


//タイムデータ
typedef struct
{
	unsigned short year;	// 年
	unsigned short month;	// 月（1～12）
	unsigned short day;		// 日（1～31）

	unsigned short hour;	// 時（0～23）
	unsigned short min;		// 分（0～59）
	unsigned short sec;		// 秒（0～59）
	unsigned short msec;	// ミリ秒（0～999）

	unsigned short wday;	// 曜日（0:日曜～6:土曜）
	unsigned short yday;	// １年のうちの日（0～365）

} TIMEDATA;

//ステータス
enum class STATUS
{
	NEW,			//新規
	WORKING,		//着手
	WAITING,		//未着手
	COMPLETED,		//完了
	DISCONTINUED,	//中止
	PENDING,		//保留
	ERROR
};

//ユーザーデータ
struct USERDATA
{
	//ID
	long id;

	//名前
	std::string name;

	//所属
	std::string affiliation;

	USERDATA(const std::string& name, const std::string& affiliation);

	USERDATA(long id, const std::string& name, const std::string& affiliation);

	USERDATA() = default;
};

//エラーの時に返す定数
const USERDATA ERRORDATA = {-1,"ERROR","EXCEPTION"};

long GetRand(long min, long max);

void GetEnter();

struct TaskData
{
	//タスクID
	long id;

	//担当者
	USERDATA pic;

	//タイトル
	std::string title;

	//内容
	std::string content;

	//優先度
	PRIORITY priority;

	//スタート時間
	TIMEDATA startTime;

	//終了予定時間
	TIMEDATA endTime;

	//残り時間
	TIMEDATA remainingTime;

	//ステータス
	STATUS status;
};