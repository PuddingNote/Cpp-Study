#include <iostream>
using namespace std;

int main(void)
{
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;		// ptr�� ������ = num �� ���
	cout << **dpref << endl;	// dptr�� ������ = num �� ���

	return 0;
}