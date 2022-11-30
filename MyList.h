#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	//�l
	T value;

	//�O�̃Z�����w���|�C���^
	Cell* prev;

	//���̃Z�����w���|�C���^
	Cell* next;

	//�R���X�g���N�^
	Cell()
	{
		//�_�~�[�m�[�h��p��
		prev = this;
		next = this;
	}

	Cell(T value_, Cell* prev_, Cell* next_)
	{
		value = value_;
		prev = prev_;
		next = next_;

	}
};

template <class T>
class Mylist
{
public:
	Mylist()
	{
		dummy = new Cell<T>();

		size = 0;
	}

	~Mylist()
	{
		//Clear();
	}

	//��ԑO�ɒǉ�
	template<typename T>
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	template<typename T>
	void PushBack(T value_)
	{
		Cell<T>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	template<typename T>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = GetCell(--num);

		//�ǉ�
		Add(value_, tmpCell);
	}

	//�C�ӂ̏ꏊ�����݂��邩�ǂ���
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	template<typename T>
	bool ChangeValue(T value_, int num)
	{

		if (Search(num))
		{
			return false;
		}

		Cell<T>* tmpCell = GetCell(num);

		//�ύX
		tmpCell->value = value_;

		return true;

	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	template<typename T>
	void Dump()
	{
		Cell<T>* ptr = dummy->next;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	/// <summary>
	/// �C�ӂ̗v�f�̕\��
	/// </summary>
	void SpecifyElement(int num)
	{
		Cell<T>* tmpCell = GetCell(num);

		std::cout << num << ':' << tmpCell->value << '\n';
	}

	//�C�ӂ̗v�f�̎擾
	template<typename T>
	T GetElement(int num)
	{
		Cell<T>* tmpCell = GetCell(num);

		return tmpCell->value;
	}

	/// <summary>
	/// ���X�g�̃T�C�Y���擾
	/// </summary>
	int Size()
	{
		return size;
	}

	//�C�ӂ̗v�f�̍폜
	bool Delete(int num)
	{
		if (Search(num))
		{
			return false;
		}

		Cell<T>* tmpCell = GetCell(num);

		tmpCell->prev->next = tmpCell->next;
		tmpCell->next->prev = tmpCell->next;

		delete tmpCell;

		size--;

		return true;
	}

	/// <summary>
	/// �~���E�����ŕ��ёւ���
	/// </summary>
	/// <param name="flag"> true�ŏ����ŕ��ёւ���</param>
	/// <returns></returns>
	template<typename T>
	void Sort(bool flag = true)
	{
		Cell<T>* tmpCell = nullptr;

		Cell<T>* tmpCell2 = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			tmpCell = GetCell(i);

			for (int j = (size - 1); j > i; j--)
			{
				tmpCell2 = GetCell(j);
				if (flag)
				{
					if (tmpCell2->value < tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (tmpCell2->value > tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}
private:

	//�_�~�[
	Cell<T>* dummy;

	//�T�C�Y
	int size;

	//�Z�����w�������ɒǉ�
	void Add(T v, Cell<T>* node)
	{
		//�V�����Z���𐶐�
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	//�C�ӂ̃Z�����擾
	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};

template <>
struct Cell<char*>
{
	//�l
	char value[64]{};

	//�O�̃Z�����w���|�C���^
	Cell* prev;

	//���̃Z�����w���|�C���^
	Cell* next;

	//�R���X�g���N�^
	Cell()
	{
		//�_�~�[�m�[�h��p��
		prev = this;
		next = this;
	}

	Cell(const char* value_, Cell* prev_, Cell* next_)
	{
		strcpy_s(value, 64, value_);
		prev = prev_;
		next = next_;

	}
};

template<>
class Mylist<char*>
{
public:
	Mylist()
	{
		dummy = new Cell<char*>();

		size = 0;
	}

	~Mylist()
	{
		//Clear();
	}

	//��ԑO�ɒǉ�
	void PushFront(const char* value_)
	{
		Cell<char*>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	void PushBack(const char* value_)
	{
		Cell<char*>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	void Insert(const char* value_, int num)
	{
		Cell<char*>* tmpCell = GetCell(--num);

		//�ǉ�
		Add(value_, tmpCell);
	}

	//�C�ӂ̏ꏊ�����݂��邩�ǂ���
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	bool ChangeValue(const char* value_, int num)
	{

		if (Search(num))
		{
			return false;
		}

		Cell<char*>* tmpCell = GetCell(num);

		//�ύX
		strcpy_s(tmpCell->value, 64, value_);

		return true;

	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void Dump()
	{
		Cell<char*>* ptr = dummy->next;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	/// <summary>
	/// �C�ӂ̗v�f�̕\��
	/// </summary>
	void SpecifyElement(int num)
	{
		Cell<char*>* tmpCell = GetCell(num);

		std::cout << num << ':' << tmpCell->value << '\n';
	}

	//�C�ӂ̗v�f�̎擾
	char* GetElement(int num)
	{
		Cell<char*>* tmpCell = GetCell(num);

		return tmpCell->value;
	}

	/// <summary>
	/// ���X�g�̃T�C�Y���擾
	/// </summary>
	int Size()
	{
		return size;
	}

	//�C�ӂ̗v�f�̍폜
	bool Delete(int num)
	{
		if (Search(num))
		{
			return false;
		}

		Cell<char*>* tmpCell = GetCell(num);

		tmpCell->prev->next = tmpCell->next;
		tmpCell->next->prev = tmpCell->next;

		delete tmpCell;

		size--;

		return true;
	}

	/// <summary>
	/// �~���E�����ŕ��ёւ���
	/// </summary>
	/// <param name="flag"> true�ŏ����ŕ��ёւ���</param>
	/// <returns></returns>
	void Sort(bool flag = true)
	{
		Cell<char*>* tmpCell = nullptr;

		Cell<char*>* tmpCell2 = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			tmpCell = GetCell(i);

			for (int j = (size - 1); j > i; j--)
			{
				tmpCell2 = GetCell(j);
				if (flag)
				{
					if (*tmpCell2->value < *tmpCell2->prev->value)
					{
						char value[64];
						strcpy_s(value, 64, tmpCell2->value);

						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (*tmpCell2->value > *tmpCell2->prev->value)
					{
						char value[64];
						strcpy_s(value, 64, tmpCell2->value);

						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}
private:

	//�_�~�[
	Cell<char*>* dummy;

	//�T�C�Y
	int size;

	//�Z�����w�������ɒǉ�
	void Add(const char* v, Cell<char*>* node)
	{
		//�V�����Z���𐶐�
		Cell<char*>* newNode = new Cell<char*>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	//�C�ӂ̃Z�����擾
	Cell<char*>* GetCell(int num)
	{
		Cell<char*>* tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};