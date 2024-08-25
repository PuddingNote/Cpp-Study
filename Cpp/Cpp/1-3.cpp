// 연산자 오버로딩 함수 호출
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
};

int main()
{
	Point p1(2, 3), p2(5, 5);

	p1 + p2;		// p1.operator+(p2)
	p1 * p2;		// p1.operator*(p2)
	p1 = p2;		// p1.operator=(p2)
	p1 == p2;		// p1.operator==(p2)
	p1 += p2;		// p1.operator+=(p2)

	return 0;
}