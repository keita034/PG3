#pragma once
#include<cassert>
#include <iostream>
#include <string>
#include <stdexcept>

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

template <typename T>
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
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
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
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//�ǉ�
		Add(value_, tmpCell);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	void ChangeValue(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		//�ύX
		tmpCell->value = value_;
	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
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

	void SpecifyElement(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
			index++;
		}

		std::cout << index << ':' << tmpCell->value << '\n';
	}

	int Size()
	{
		return size;
	}

private:

	//�_�~�[
	Cell<T>* dummy;

	int size;

	//�Z�����w�������ɒǉ�
	void Add(T v, Cell<T>* node)
	{
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}
};


