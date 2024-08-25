// ���� �Լ� ������ �����ε�(- ������)
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
	// friend�� ����ϸ� xpos, ypos�� ���� ���� �����ϳ� ����ȭ�� ������
	//friend const Point operator-(const Point& p1, const Point& p2);
};

//const Point operator-(const Point& p1, const Point& p2)
//{
//	return Point(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
//}

const Point operator-(const Point& p1, const Point& p2) 
{
	return Point(p1.GetX() - p2.GetX(), p1.GetY() - p2.GetY());
}

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 - p2;

	p3.Print();

	return 0;
}