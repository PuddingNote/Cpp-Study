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
	cout << *pref << endl;		// ptr의 참조자 = num 값 출력
	cout << **dpref << endl;	// dptr의 참조자 = num 값 출력

	return 0;
}