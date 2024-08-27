// Point ��ü���� �Լ� ���ø� Ư��ȭ ����
#include <iostream>
using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
};

template <class T>
void Print(T a)
{
	cout << a << endl;
}

template <>
void Print(Point a)
{
	cout << "Print Ư��ȭ ����: ";
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);		// Ư��ȭ ���� ȣ��
}