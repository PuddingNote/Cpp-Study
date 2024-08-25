// ++ 연산자 오버로딩 완성
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
	const Point& operator++()
	{
		++xpos;
		++ypos;
		return *this;
	}
	const Point& operator++(int)
	{
		Point pt(xpos, ypos);
		++xpos;
		++ypos;
		return pt;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point result;

	result = ++p1;		// p1.operator++()
	p1.Print();
	result.Print();

	result = p2++;		// p1.operator++(0)
	p2.Print();
	result.Print();

	return 0;
}