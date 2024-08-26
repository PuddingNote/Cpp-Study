// Point 클래스의 일반 포인터 사용
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
	Point* p1 = new Point(2, 3);
	Point* p2 = new Point(5, 5);

	p1->Print();
	p2->Print();

	delete p1;
	delete p2;

	return 0;
}