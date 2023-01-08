#pragma once

enum class EnemyState
{
	APPROACH,
	ATTACK,
	ESCAPE,
	STATEMAX
};

class Enemy
{
public:

	Enemy() = default;
	~Enemy() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void Approach();
	void Attack();
	void Escape();


private:

	EnemyState state;

	static void (Enemy::* stateTable[])();
};

