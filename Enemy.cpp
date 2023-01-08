#include "Enemy.h"
#include<stdio.h>
#include<Windows.h>

void (Enemy::* Enemy::stateTable[])() =
{
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Escape,
};

void Enemy::Init()
{
	printf("“G‚ª¶‚Ü‚ê‚½\n");
	state = EnemyState::APPROACH;
}

void Enemy::Updata()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

void Enemy::Approach()
{
	printf("“G‚ªÚ‹ß‚µ‚Ä—ˆ‚½\n");
	state = EnemyState::ATTACK;
}

void Enemy::Attack()
{
	printf("“G‚ÌUŒ‚\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("“G‚Í“¦‚°o‚µ‚½\n");
}

