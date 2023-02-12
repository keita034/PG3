#pragma once
#include<unordered_map>
#include<string>
#include<random>

#include"Constant.h"

class UserDataList
{
public:
	UserDataList();
	~UserDataList() = default;

	/// <summary>
	/// �t�@�C�����点�[����ǂݍ���
	/// </summary>
	/// <param name="path">�t�@�C���p�X</param>
	void ReadData(const std::string& path);

	/// <summary>
	/// �f�[�^��ǉ�
	/// </summary>
	/// <param name="data">���[�U�[�f�[�^</param>
	void AddData(USERDATA& data);

	/// <summary>
	/// �f�[�^���폜
	/// </summary>
	/// <param name="id">���[�U�[ID</param>
	void SubData(long id);

	/// <summary>
	/// �f�[�^���N���A
	/// </summary>
	void ClearData();

	/// <summary>
	/// �f�[�^���擾
	/// </summary>
	/// <param name="id">���[�U�[ID</param>
	/// <returns>���[�U�[�f�[�^</returns>
	USERDATA* GetData(long id);

	/// <summary>
	/// �f�[�^���擾
	/// </summary>
	/// <param name="name">���[�U�[���O</param>
	/// <returns>���[�U�[�f�[�^</returns>
	USERDATA* GetData(const std::string& name);

private:

	std::unordered_map<long, USERDATA> list;

};

