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
		for (int i = size; i != -1; i--)
		{
			Delete(i);
		}
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
		//�C�ӂ̏ꏊ���擾
		Cell<T>* tmpCell = GetCell(--num);

		//�ǉ�
		Add(value_, tmpCell);
	}

	//�C�ӂ̏ꏊ�����݂��邩�ǂ���
	bool Search(int num)
	{
		if (num < 0 || num>=size)
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

		if (!Search(num))
		{
			return false;
		}

		//�C�ӂ̏ꏊ���擾
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
		//�C�ӂ̏ꏊ���擾
		Cell<T>* cell = GetCell(num);

		std::cout << num << ':' << cell->value << '\n';
	}

	//�C�ӂ̗v�f�̎擾
	template<typename T>
	T GetElement(int num)
	{
		//�C�ӂ̏ꏊ���擾
		Cell<T>* cell = GetCell(num);

		return cell->value;
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
		if (!Search(num))
		{
			return false;
		}

		//�C�ӂ̏ꏊ���擾
		Cell<T>* cell = GetCell(num);

		cell->prev->next = cell->next;
		cell->next->prev = cell->next;

		delete cell;

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
		Cell<T>* cell = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{

			for (int j = (size - 1); j > i; j--)
			{
				//�C�ӂ̏ꏊ���擾
				cell = GetCell(j);
				
				if (flag)
				{
					if (cell->value < cell->prev->value)
					{
						T element = cell->value;
						ChangeValue(cell->prev->value, j);
						ChangeValue(element, j - 1);
					}
				}
				else
				{
					if (cell->value > cell->prev->value)
					{
						T element = cell->value;
						ChangeValue(cell->prev->value, j);
						ChangeValue(element, j - 1);
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
		Cell<T>* cell = dummy;

		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		return cell;
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
		for (int i = size; i != -1; i--)
		{
			Delete(i);
		}
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
		//�C�ӂ̏ꏊ���擾
		Cell<char*>* cell = GetCell(--num);

		//�ǉ�
		Add(value_, cell);
	}

	//�C�ӂ̏ꏊ�����݂��邩�ǂ���
	bool Search(int num)
	{
		if (num < 0 || num>=size)
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

		if (!Search(num))
		{
			return false;
		}

		//�C�ӂ̏ꏊ���擾
		Cell<char*>* cell = GetCell(num);

		//�ύX
		strcpy_s(cell->value, 64, value_);

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
		//�C�ӂ̏ꏊ���擾
		Cell<char*>* cell = GetCell(num);

		std::cout << num << ':' << cell->value << '\n';
	}

	//�C�ӂ̗v�f�̎擾
	char* GetElement(int num)
	{
		//�C�ӂ̏ꏊ���擾
		Cell<char*>* cell = GetCell(num);

		return cell->value;
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
		if (!Search(num))
		{
			return false;
		}

		//�C�ӂ̏ꏊ���擾
		Cell<char*>* cell = GetCell(num);

		cell->prev->next = cell->next;
		cell->next->prev = cell->next;

		delete cell;

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
		Cell<char*>* cell = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			for (int j = (size - 1); j > i; j--)
			{
				//�C�ӂ̏ꏊ���擾
				cell = GetCell(j);

				if (flag)
				{
					if (*cell->value < *cell->prev->value)
					{
						char element[64];
						strcpy_s(element, 64, cell->value);

						ChangeValue(cell->prev->value, j);
						ChangeValue(element, j - 1);
					}
				}
				else
				{
					if (*cell->value > *cell->prev->value)
					{
						char element[64];
						strcpy_s(element, 64, cell->value);

						ChangeValue(cell->prev->value, j);
						ChangeValue(element, j - 1);
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
		Cell<char*>* cell = dummy;

		
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		return cell;
	}
};