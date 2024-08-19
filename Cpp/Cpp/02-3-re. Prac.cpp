//#include <iostream>
//using namespace std;
//
//typedef struct __Point
//{
//	int xpos;
//	int ypos;
//} Point;
//
//Point& PntAdder(const Point& p1, const Point& p2)
//{
//	Point* p = new Point;
//	p->xpos = p1.xpos + p2.xpos;
//	p->ypos = p1.ypos + p2.ypos;
//
//	return *p;
//}
//
//int main(void)
//{
//	Point* p1 = new Point;
//	Point* p2 = new Point;
//
//	p1->xpos = 1;
//	p1->ypos = 2;
//
//	p2->xpos = 3;
//	p2->ypos = 4;
//
//	Point& p = PntAdder(*p1, *p2);
//
//	cout << p.xpos << ", " << p.ypos << endl;
//
//	delete p1;
//	delete p2;
//	delete& p;
//	return 0;
//}

#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point PntAdder(const Point p1, const Point p2)
{
	Point p;
	p.xpos = p1.xpos + p2.xpos;
	p.ypos = p1.ypos + p2.ypos;

	return p;
}

int main(void)
{
	Point p1;
	Point p2;

	p1.xpos = 1;
	p1.ypos = 2;

	p2.xpos = 3;
	p2.ypos = 4;

	Point p = PntAdder(p1, p2);

	cout << p.xpos << ", " << p.ypos << endl;

	return 0;
}