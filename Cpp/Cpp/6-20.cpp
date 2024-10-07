// const와 반복자
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

	vector<int>::iterator iter = v.begin();
	int* p = arr;
	cout << *iter << ", " << *p << endl;


	vector<int>::const_iterator citer = v.begin();
	const int* cp = arr;
	cout << *citer << ", " << *cp << endl;


	const vector<int>::iterator iter_const = v.begin();
	int* const p_const = arr;
	cout << *iter_const << ", " << *p_const << endl;


	const vector<int>::const_iterator citer_const = v.begin();
	const int* const cp_const = arr;
	cout << *citer_const << ", " << *cp_const << endl;

	return 0;
}