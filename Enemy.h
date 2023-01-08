#pragma once
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



private:

	/// <summary>
	/// “G‚ğ“|‚·
	/// </summary>
	void Kill();

private:

	static bool isAlive;
};

