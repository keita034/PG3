#include "Enemy.h"
#include<stdio.h>
#include<Windows.h>

bool Enemy::isAlive = true;

void Enemy::Init()
{
	printf("“G‚ª¶‚Ü‚ê‚½\n");
}

void Enemy::Updata()
{
	Kill();
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("“G‚Í¶‚«‚Ä‚¢‚é\n");
	}
	else
	{
		printf("“G‚Í€‚ñ‚Å‚¢‚é\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("“G‚ª€‚ñ‚¾\n");
}