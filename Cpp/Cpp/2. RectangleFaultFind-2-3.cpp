#include <iostream>
#include "2. Point-1-1.h"
#include "2. Rectangle-2-1.h"
using namespace std;

int main(void)
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4))
		cout << "초기화 실패" << endl;
	if (!pos1.InitMembers(2, 4))
		cout << "초기화 실패" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9))
		cout << "초기화 실패" << endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1))
		cout << "직사각형 초기화 실패" << endl;

	if (!rec.InitMembers(pos1, pos2))
		cout << "직사각형 초기화 실패" << endl;

	rec.ShowRecInfo();
	return 0;
}