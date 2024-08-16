#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(const char* str)
{
	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			throw str[i];
		}
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));	// ���ڿ��� ������ ���·� ��ȯ�ϴ� ����
	}
	return num;
}

int main(void)
{
	char str1[100];
	char str2[100];

	while (1)
	{
		cout << "�� ���� ���� �Է�:";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "���� " << ch << "�� �ԷµǾ����ϴ�." << endl;
			cout << "���Է� �����մϴ�." << endl << endl;
		}
	}
	cout << "���α׷��� �����մϴ�." << endl;

	return 0;
}