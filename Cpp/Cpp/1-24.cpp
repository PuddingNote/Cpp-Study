// Point 클래스의 생성자
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
	Point p;
	p.Print();

	p = 10;
	p.Print();

	return 0;
}