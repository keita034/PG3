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
	printf("�G�����܂ꂽ\n");
	state = EnemyState::APPROACH;
}

void Enemy::Updata()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

void Enemy::Approach()
{
	printf("�G���ڋ߂��ė���\n");
	state = EnemyState::ATTACK;
}

void Enemy::Attack()
{
	printf("�G�̍U��\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("�G�͓����o����\n");
}

