#include <iostream>
using namespace std;

void HanoiTowerMove(int num, char start, char B, char end)
{
	if (num == 1)
	{
		cout << "���� " << num << "�� " << start << "���� " << end << "�� �̵�" << endl;
	}
	else
	{
		HanoiTowerMove(num - 1, start, end, B);
		cout << "���� " << num << "�� " << start << "���� " << end << "�� �̵�" << endl;
		HanoiTowerMove(num - 1, B, start, end);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');

	return 0;
}