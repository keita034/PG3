#include "Enemy.h"
#include<stdio.h>
#include<Windows.h>

bool Enemy::isAlive = true;

void Enemy::Init()
{
	printf("�G�����܂ꂽ\n");
}

void Enemy::Updata()
{
	Kill();
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("�G�͐����Ă���\n");
	}
	else
	{
		printf("�G�͎���ł���\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("�G������\n");
}