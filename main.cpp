#include <stdio.h>
#include<list>
#include<vector>
int main()
{
	//駅番号
	int index = 1;

	std::list<const char*>yamanoteLine{
		"Tokyo", "Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo","Otsuka",
		"Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo","Shinjuku",
		"Yoyogi","Harajuku","Shibuya","Ebisu","Meguro",
		"Gotanda","Osaki","Shinagawa","Tamachi","Hamamatsucho",
		"Shimbashi","Yurakucho"
	};

	//一覧を表示
	printf("1970年当時の山手線駅一覧(英語名)\n");
	for (const char* station : yamanoteLine)
	{
		printf("JY%02d:%s\n", index,station);
		index++;
	}
	printf("\n");

	//日暮里の前に西日暮里を追加
	for (std::list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			itr = yamanoteLine.insert(itr, "Nishi-Nippori");

			break;
		}
	}

	//一覧を表示
	index = 1;
	printf("2019年当時の山手線駅一覧(英語名)\n");
	for (const char* station : yamanoteLine)
	{
		printf("JY%02d:%s\n", index, station);
		index++;
	}
	printf("\n");

	//品川の前に高輪ゲートウェイを追加
	for (std::list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = yamanoteLine.insert(itr, "Takanawa Gateway");

			break;
		}
	}

	//一覧を表示
	index = 1;
	printf("2022年当時の山手線駅一覧(英語名)\n");
	for (const char* station : yamanoteLine)
	{
		printf("JY%02d:%s\n", index, station);
		index++;
	}

	return 0;
}