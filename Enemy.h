#pragma once
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



private:

	/// <summary>
	/// �G��|��
	/// </summary>
	void Kill();

private:

	static bool isAlive;
};

