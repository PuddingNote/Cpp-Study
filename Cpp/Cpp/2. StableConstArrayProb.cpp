#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int index)
	{
		if (index < 0 || index >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[index];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int i = 0; i < len; i++)
	{
		cout << ref[i] << endl;	// ref.operator[] (i); - operator[] 함수가 const가 아니기때문에 에러 - 다음예제에서 해결
	}
}

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}

	ShowAllData(arr);

	return 0;
}