#include <iostream>
using namespace std;

template <class T = int, int len = 7>	// Default Value 지정!
class SimpleArray
{
private:
	T arr[len];

public:
	T& operator[] (int index)
	{
		return arr[index];
	}
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i] = ref.arr[i];
		}
		return *this;
	}
};

int main(void)
{
	SimpleArray<> arr;	// Default값이 있어도 <>기호는 반드시 추가되어야 한다.
	for (int i = 0; i < 7; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}