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
	/// �V�[���؂�ւ�
	/// </summary>
	/// <param name="sceneNo">�V�[���ԍ�</param>
	void ChangeScene(int& sceneNo);

	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns>�V���O���g���C���X�^���X</returns>
	static SceneManager* GetInstance();

private:

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

private:
	// private�ȃR���X�g���N�^�i�V���O���g���p�^�[���j
	SceneManager() = default;
	// private�ȃf�X�g���N�^�i�V���O���g���p�^�[���j
	~SceneManager() = default;
	// �R�s�[�R���X�g���N�^���֎~�i�V���O���g���p�^�[���j
	SceneManager(const SceneManager& obj) = delete;
	// �R�s�[������Z�q���֎~�i�V���O���g���p�^�[���j
	void operator=(const SceneManager& obj) = delete;
};
