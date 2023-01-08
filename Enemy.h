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
	/// ‰Šú‰»
	/// </summary>
	void Init();

	/// <summary>
	/// XV
	/// </summary>
	void Updata();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

	void Approach();
	void Attack();
	void Escape();


private:

	EnemyState state;

	static void (Enemy::* stateTable[])();
};

