// operator+() 함수 정의
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
	void operator+(Point p)
	{
		cout << "operator+() 함수 호출" << endl;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);

	p1 + p2;

	return 0;
}