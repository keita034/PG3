#pragma once

enum SceneNum
{
	TITLE,
	NEWGAME,
	GAMEPLAY,
	GAMECLEAR
};

class SceneManager final
{
public:

	/// <summary>
	/// シーン切り替え
	/// </summary>
	/// <param name="sceneNo">シーン番号</param>
	void ChangeScene(int& sceneNo);

	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>シングルトンインスタンス</returns>
	static SceneManager* GetInstance();

private:

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

private:
	// privateなコンストラクタ（シングルトンパターン）
	SceneManager() = default;
	// privateなデストラクタ（シングルトンパターン）
	~SceneManager() = default;
	// コピーコンストラクタを禁止（シングルトンパターン）
	SceneManager(const SceneManager& obj) = delete;
	// コピー代入演算子を禁止（シングルトンパターン）
	void operator=(const SceneManager& obj) = delete;
};
