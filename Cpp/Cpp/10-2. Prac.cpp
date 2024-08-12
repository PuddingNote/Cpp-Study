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
	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}

	// 문제 2
	friend Point operator~(const Point& ref);
};

Point operator~(const Point& ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2 = -pos1;
	Point pos3 = ~pos1;

	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}