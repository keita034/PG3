#pragma once
#include<cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>

template <typename T>
struct Cell
{
	//値
	T value;

	//前のセルを指すポインタ
	Cell* prev;

	//次のセルを指すポインタ
	Cell* next;

	//コンストラクタ
	Cell()
	{
		//ダミーノードを用意
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

	//一番前に追加
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//追加
		Add(value_, tmpCell);
	}

	//
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		//変更
		tmpCell->value = value_;

		return true;

	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = dummy->next;

		std::cout << "要素一覧:{" << std::endl;

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

	T GetElement(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell->value;
	}

	int Size()
	{
		return size;
	}

	bool Delete(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		tmpCell->prev->next = tmpCell->next;
		tmpCell->next->prev = tmpCell->next;

		delete tmpCell;

		size--;

		return true;
	}


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

	//ダミー
	Cell<T>* dummy;

	int size;

	//セルが指した後ろに追加
	void Add(T v, Cell<T>* node)
	{
		//新しいセルを生成
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};


