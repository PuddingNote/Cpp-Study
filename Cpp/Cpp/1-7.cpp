// ++ ������ ����
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	void operator++()		// ���� ++ ������
	{

	}
	void operator++(int)	// ���� ++ ������
	{

	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);

	++p1;		// p1.operator++()

	p2++;		// p1.operator++(0)

	return 0;
}