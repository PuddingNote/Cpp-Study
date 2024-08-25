// ��� ��ü�� ��ȯ�ϴ� [] ������ �����ε�
#include <iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	int capacity;

	// ���� �Լ� ����(���� ������, ���� ���Կ�����)
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
	//ar2[0] = 100;				// ����! ��� ��ü(��)�� ��ȯ�ϹǷ� ������ �� ����.

	return 0;
}