#include "Enemy.h"
#include<stdio.h>
#include<Windows.h>

bool Enemy::isAlive = true;

void Enemy::Init()
{
	printf("敵が生まれた\n");
}

void Enemy::Updata()
{
		Kill();
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("敵は生きている\n");
	}
	else
	{
		printf("敵は死んでいる\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("敵が死んだ\n");
}