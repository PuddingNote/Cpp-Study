#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA	 = 1111111;
	const static int CANADA	 = 2222222;
	const static int CHINA	 = 3333333;
	const static int KOREA	 = 4444444;
};

int main(void)
{
	cout << "���þ� ����: " << CountryArea::RUSSIA << "km" << endl;
	cout << "ĳ���� ����: " << CountryArea::CANADA << "km" << endl;
	cout << "��  �� ����: " << CountryArea::CHINA << "km" << endl;
	cout << "��  �� ����: " << CountryArea::KOREA << "km" << endl;

	return 0;
}