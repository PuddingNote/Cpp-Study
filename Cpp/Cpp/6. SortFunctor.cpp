#include <iostream>
using namespace std;

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class DescendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class DataStorage
{
private:
	int* arr;
	int index;
	const int MAX_LEN;

public:
	DataStorage(int arrlen) : index(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= index)
		{
			cout << "더이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[index++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < index; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	void SortData(const SortRule& functor)
	{
		for (int i = 0; i < (index - 1); i++)
		{
			for (int j = 0; j < (index - 1); j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.ShowAllData();

	storage.SortData(AscendingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	return 0;
}