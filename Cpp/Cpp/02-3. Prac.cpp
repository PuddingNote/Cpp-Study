#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* ptr = new Point;

	ptr->xpos = p1.xpos + p2.xpos;
	ptr->ypos = p1.ypos + p2.ypos;
	
	return *ptr;
}

int main(void)
{
	Point* p1 = new Point;
	p1->xpos = 10;
	p1->ypos = 10;
	
	Point* p2 = new Point;
	p2->xpos = 20;
	p2->ypos = 20;

	Point& pref = PntAdder(*p1, *p2);

	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete p1;
	delete p2;
	delete& pref;

	return 0;
}

