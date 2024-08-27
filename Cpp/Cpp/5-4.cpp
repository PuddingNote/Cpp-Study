// deque의 임의 접근 반복자
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter = dq.begin();
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl << endl;

	iter += 2;
	cout << *iter << endl << endl;

	deque<int>::iterator iter2 = iter + 2;
	cout << *iter << endl;

	return 0;
}