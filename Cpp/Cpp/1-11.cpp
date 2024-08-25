// != 연산자 오버로딩
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
	bool operator!=(const Point& p) const
	{
		return !(*this == p);	// p1이 p2와 같으면 false 반환 / 다르면 true 반환
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5), p3(2, 3);

	if (p1 != p2)	// p1.operator!=(p2)
	{
		cout << "p1 != p2" << endl;
	}
	if (p1 != p3)	// p1.operator!=(p3)
	{
		cout << "p1 != p3" << endl;
	}

	return 0;
}