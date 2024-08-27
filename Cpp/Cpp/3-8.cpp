// plus�� minus �Լ� ��ü ����
#include <iostream>
#include <functional>
using namespace std;

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

struct Minus
{
	int operator()(int a, int b)
	{
		return a - b;
	}
};

int main()
{
	// �����
	cout << Plus()(10, 20) << endl;
	cout << Minus()(10, 20) << endl;

	// STL
	cout << plus<int>()(10, 20) << endl;
	cout << minus<int>()(10, 20) << endl;

	return 0;
}