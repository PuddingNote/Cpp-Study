// == 연산자 중복
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
	bool operator==(const Point& p) const
	{
		return xpos == p.xpos && ypos == p.ypos ? true : false;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5), p3(2, 3);

	if (p1 == p2)	// p1.operator==(p2)
	{
		cout << "p1 == p2" << endl;
	}
	if (p1 == p3)	// p1.operator==(p3)
	{
		cout << "p1 == p3" << endl;
	}

	return 0;
}