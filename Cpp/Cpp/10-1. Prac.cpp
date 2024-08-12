#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << "]" << endl;
	}
	// 문제 1
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);

	// 문제 2
	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	// 문제 3
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos != pos2.xpos && pos1.ypos != pos2.ypos)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition();	// 객체를 반환하므로 함수호출 가능
	(pos2 += pos3).ShowPosition();	// 반환형이 참조형이므로 함수호출 가능
	(pos2 -= pos3).ShowPosition();	// 반환형이 참조형이므로 함수호출 가능

	if (pos2 == pos3)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

	if (pos2 != pos3)
	{
		cout << "not equal" << endl;
	}
	else
	{
		cout << "equal" << endl;
	}

	return 0;
}