#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	const int* ptr = &num;
	const int* &ref = ptr;
	
	cout << "num: " << num << endl;
	cout << "*ptr: " << *ptr << endl;
	cout << "*ref: " << *ref << endl;

	cout << "&num: " << &num << endl;
	cout << "ptr: " << ptr << endl;
	cout << "ref: " << ref << endl;
	return 0;
}