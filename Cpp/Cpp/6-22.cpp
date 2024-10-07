// insert() 멤버 함수의 사용
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int arr[5] = { 10,20,30,40,50 };

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;
	vector<int>::iterator iter2;

	iter2 = v.insert(iter, 100);

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "iter2: " << *iter2 << endl;

	return 0;
}