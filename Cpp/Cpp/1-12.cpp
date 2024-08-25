// 멤버 함수 연산자 오버로딩(- 연산자)
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
	int GetX() const
	{
		return xpos;
	}
	int GetY() const
	{
		return ypos;
	}

	const Point operator-(const Point& p) const
	{
		return Point(xpos - p.xpos, ypos - p.ypos);
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 - p2;

	p3.Print();

	return 0;
}