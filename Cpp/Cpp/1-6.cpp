// operator+() 함수 완성
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
	const Point operator+(const Point& p) const
	{
		Point pt;
		pt.xpos = xpos + p.xpos;
		pt.ypos = ypos + p.ypos;

		return pt;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 + p2;			// 컴파일러가 p1.operator+(p2)로 해석해서 호출
	p3.Print();
	p3 = p1.operator+(p2);	// 직접 호출
	p3.Print();

	return 0;
}