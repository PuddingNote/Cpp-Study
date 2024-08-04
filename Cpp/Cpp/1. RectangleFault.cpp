#include <iostream>
using namespace std;

class Point
{
public:
	int x;	// 0 ~ 100
	int y;	// 0 ~ 100
};

class Rectangle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "�� ���: " << '[' << upLeft.x << ", " << upLeft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ", " << lowRight.y << ']' << endl;
	}
};

int main(void)
{
	Point pos1 = { -2,4 };
	Point pos2 = { 5,9 };
	Rectangle rec = { pos2,pos1 };
	rec.ShowRecInfo();

	return 0;
}