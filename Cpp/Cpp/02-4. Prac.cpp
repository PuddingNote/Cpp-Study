// 문제 1
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char a[20] = "Hello";
	char b[10] = "World";
	char c[20];

	cout << strlen(a) << endl;
	cout << strcat(a, b) << endl;
	cout << strcpy(c, b) << endl;
	cout << strcmp(b, c) << endl;

	return 0;
}

// 문제 2
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}

	return 0;
}