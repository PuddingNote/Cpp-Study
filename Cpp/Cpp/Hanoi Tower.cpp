#include <iostream>
using namespace std;

void HanoiTowerMove(int num, char start, char B, char end)
{
	if (num == 1)
	{
		cout << "원반 " << num << "을 " << start << "에서 " << end << "로 이동" << endl;
	}
	else
	{
		HanoiTowerMove(num - 1, start, end, B);
		cout << "원반 " << num << "을 " << start << "에서 " << end << "로 이동" << endl;
		HanoiTowerMove(num - 1, B, start, end);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');

	return 0;
}