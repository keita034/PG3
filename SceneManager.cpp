#include "SceneManager.h"
#include "DxLib.h"

void SceneManager::ChangeScene(int& sceneNo)
{
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);

	switch (sceneNo)
	{
	case 0: // Title

		SetBackgroundColor(0x0f, 0x00, 0xf0);

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 1;
		}

		break;

	case 1: // NewGame

		SetBackgroundColor(0x20, 0x05, 0x30);

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 2;
		}

		break;

	case 2: // GamePlay

		SetBackgroundColor(0xa0, 0xf0, 0x0f);

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 次のシーンへ
			sceneNo = 3;
		}

		break;

	case 3: // GameClear

		SetBackgroundColor(0xa0, 0x70, 0x09);

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			// 最初のシーンへ
			sceneNo = 0;
		}

		break;
	}

	int Cr = GetColor(255, 255, 255);
	DrawFormatString(50, 50, Cr, _T("SceneNo: %d"), sceneNo);
	DrawFormatString(50, 70, Cr, _T("Press Space to Scene Change"));
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}