#include <iostream>
#include "2. Rectangle-2-1.h"
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{
		cout << "�߸��� ��ġ���� ����" << endl;
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{
	cout << "�� ��� " << '[' << upLeft.GetX() << ", " << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ� " << '[' << lowRight.GetX() << ", " << lowRight.GetY() << ']' << endl << endl;
}