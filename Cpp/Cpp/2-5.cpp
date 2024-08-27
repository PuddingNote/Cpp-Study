// Point 클래스의 멤버 함수 포인터
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	void PrintInt(int n)
	{
		cout << "테스트 정수: " << n << endl;
	}
};

int main()
{
	Point pt(2, 3);
	Point* p = &pt;

	void (Point:: * pf1) () const;		// 멤버 함수 포인터 선언
	pf1 = &Point::Print;

	void (Point:: * pf2) (int);			// 멤버 함수 포인터 선언
	pf2 = &Point::PrintInt;

	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	// 객체로 멤버 함수 포인터를 이용한 호출
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;

	// 주소로 멤버 함수 포인터를 이용한 호출
	(p->*pf1)();
	(p->*pf2)(10);

	return 0;
}