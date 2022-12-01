#pragma once
#include <iostream>

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
		for (int i = size; i != -1; i--)
		{
			Delete(i);
		}
	}

	//一番前に追加
	template<typename T>
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	template<typename T>
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
	template<typename T>
	void Insert(T value_, int num)
	{
		//任意の場所を取得
		Cell<T>* tmpCell = GetCell(--num);

		//追加
		Add(value_, tmpCell);
	}

	//任意の場所が存在するかどうか
	bool Search(int num)
	{
		if (num < 0 || num>=size)
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
	template<typename T>
	bool ChangeValue(T value_, int num)
	{

		if (!Search(num))
		{
			return false;
		}

		//任意の場所を取得
		Cell<T>* tmpCell = GetCell(num);

		//変更
		tmpCell->value = value_;

		return true;
	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	template<typename T>
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

	/// <summary>
	/// 任意の要素の表示
	/// </summary>
	void SpecifyElement(int num)
	{
		//任意の場所を取得
		Cell<T>* cell = GetCell(num);

		std::cout << num << ':' << cell->value << '\n';
	}

	//任意の要素の取得
	template<typename T>
	T GetElement(int num)
	{
		//任意の場所を取得
		Cell<T>* cell = GetCell(num);

		return cell->value;
	}

	/// <summary>
	/// リストのサイズを取得
	/// </summary>
	int Size()
	{
		return size;
	}

	//任意の要素の削除
	bool Delete(int num)
	{
		if (!Search(num))
		{
			return false;
		}

		//任意の場所を取得
		Cell<T>* cell = GetCell(num);

		cell->prev->next = cell->next;
		cell->next->prev = cell->next;

		delete cell;

		size--;

		return true;
	}

	/// <summary>
	/// 降順・昇順で並び替える
	/// </summary>
	/// <param name="flag"> trueで昇順で並び替える</param>
	/// <returns></returns>
	template<typename T>
	void Sort(bool flag = true)
	{
		Cell<T>* cell = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{

			for (int j = (size - 1); j > i; j--)
			{
				//任意の場所を取得
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

	//ダミー
	Cell<T>* dummy;

	//サイズ
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

	//任意のセルを取得
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
	//値
	char value[64]{};

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

	//一番前に追加
	void PushFront(const char* value_)
	{
		Cell<char*>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(const char* value_)
	{
		Cell<char*>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(const char* value_, int num)
	{
		//任意の場所を取得
		Cell<char*>* cell = GetCell(--num);

		//追加
		Add(value_, cell);
	}

	//任意の場所が存在するかどうか
	bool Search(int num)
	{
		if (num < 0 || num>=size)
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
	bool ChangeValue(const char* value_, int num)
	{

		if (!Search(num))
		{
			return false;
		}

		//任意の場所を取得
		Cell<char*>* cell = GetCell(num);

		//変更
		strcpy_s(cell->value, 64, value_);

		return true;

	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<char*>* ptr = dummy->next;

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

	/// <summary>
	/// 任意の要素の表示
	/// </summary>
	void SpecifyElement(int num)
	{
		//任意の場所を取得
		Cell<char*>* cell = GetCell(num);

		std::cout << num << ':' << cell->value << '\n';
	}

	//任意の要素の取得
	char* GetElement(int num)
	{
		//任意の場所を取得
		Cell<char*>* cell = GetCell(num);

		return cell->value;
	}

	/// <summary>
	/// リストのサイズを取得
	/// </summary>
	int Size()
	{
		return size;
	}

	//任意の要素の削除
	bool Delete(int num)
	{
		if (!Search(num))
		{
			return false;
		}

		//任意の場所を取得
		Cell<char*>* cell = GetCell(num);

		cell->prev->next = cell->next;
		cell->next->prev = cell->next;

		delete cell;

		size--;

		return true;
	}

	/// <summary>
	/// 降順・昇順で並び替える
	/// </summary>
	/// <param name="flag"> trueで昇順で並び替える</param>
	/// <returns></returns>
	void Sort(bool flag = true)
	{
		Cell<char*>* cell = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			for (int j = (size - 1); j > i; j--)
			{
				//任意の場所を取得
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

	//ダミー
	Cell<char*>* dummy;

	//サイズ
	int size;

	//セルが指した後ろに追加
	void Add(const char* v, Cell<char*>* node)
	{
		//新しいセルを生成
		Cell<char*>* newNode = new Cell<char*>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	//任意のセルを取得
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