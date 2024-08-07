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
	cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "중  국 면적: " << CountryArea::CHINA << "km" << endl;
	cout << "한  국 면적: " << CountryArea::KOREA << "km" << endl;

	return 0;
}