// 상수 객체를 반환하는 [] 연산자 오버로딩
#include <iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	int capacity;

	// 복사 함수 생략(복사 생성자, 복사 대입연산자)
public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}
	~Array()
	{
		delete[] arr;
	}
	void Add(int data)
	{
		if (size < capacity)
		{
			arr[size++] = data;
		}
	}
	int Size() const
	{
		return size;
	}
	int operator[](int index) const
	{
		return arr[index];
	}
	int& operator[](int index)
	{
		return arr[index];
	}
};

int main()
{
	Array ar1(10);

	ar1.Add(10);
	ar1.Add(20);
	ar1.Add(30);

	cout << ar1[0] << endl;		// ar1.operator[](int)
	cout << endl;

	const Array& ar2 = ar1;
	cout << ar2[0] << endl;		// ar2.operator[](int) const
	cout << endl;

	ar1[0] = 100;				// ar1.operator[](int)
	//ar2[0] = 100;				// 에러! 상수 객체(값)를 반환하므로 대입할 수 없다.

	return 0;
}