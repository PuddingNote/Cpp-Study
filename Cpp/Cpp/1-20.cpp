// 스마트 포인터 PointPtr 클래스 생성
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
};

// 동적으로 생성한 Point객체를 자동으로 소멸자 실행 후 삭제 (실수로 delete를 안써서 생기는 메모리 누수 방지)
class PointPtr
{
private:
	Point* ptr;

public:
	PointPtr(Point* p) : ptr(p) { }
	~PointPtr()
	{
		delete ptr;
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3);
	PointPtr p2 = new Point(5, 5);
	
	// 아직 사용 못함
	p1->Print();
	p2->Print();

	delete p1;
	delete p2;

	return 0;
}