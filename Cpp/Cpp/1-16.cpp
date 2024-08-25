// Point의 [] 연산자 중복
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	int operator[](int index) const
	{
		if (index == 0)
		{
			return xpos;
		}
		else if (index == 1)
		{
			return ypos;
		}
		else
		{
			throw "이럴 수는 없는 거야!";
		}
	}
};

int main()
{
	Point p(2, 3);

	p.Print();

	cout << p[0] << ", "		// p.operator[](0)
		<< p[1] << endl;		// p.operator[](1)

	return 0;
}