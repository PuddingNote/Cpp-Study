// vector의 임의 접근 반복자
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl << endl;

	iter += 2;
	cout << *iter << endl << endl;

	vector<int>::iterator iter2 = iter + 2;
	cout << *iter << endl;

	return 0;
}