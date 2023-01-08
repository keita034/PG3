#include <stdio.h>
#include <stdlib.h>
#include<memory>
#include<vector>
#include"Enemy.h"

int main()
{

	std::vector<std::unique_ptr<Enemy>>enemys;

	int enemyNum = 5;

	printf("“G‚Ì”‚Í%d‘Ì\n", enemyNum);
	printf("\n");

	//“G‚Ì¶¬
	for (int i = 0; i < enemyNum; i++)
	{
		std::unique_ptr<Enemy> enemy;
		enemy = std::make_unique<Enemy>();
		enemy->Init();

		enemys.push_back(std::move(enemy));
	}
	printf("\n");


	//“G‚Ìó‘Ô•\¦
	for (std::unique_ptr<Enemy >& enemy : enemys)
	{
		enemy->Updata();
	}
	printf("\n");

	//“G‚Ìó‘Ô•\¦
	for (std::unique_ptr<Enemy >& enemy : enemys)
	{
		enemy->Updata();
	}
	printf("\n");

	//“G‚Ìó‘Ô•\¦
	for (std::unique_ptr<Enemy >& enemy : enemys)
	{
		enemy->Updata();
	}
	printf("\n");

	enemys.clear();

	system("pause");

	return 0;
}