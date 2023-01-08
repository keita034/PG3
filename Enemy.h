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
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 更新
	/// </summary>
	void Updata();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void Approach();
	void Attack();
	void Escape();


private:

	EnemyState state;

	static void (Enemy::* stateTable[])();
};

