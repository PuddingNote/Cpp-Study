#include "4-1. ArrayTemplate.h"
#include "4-2. Point.h"

int main(void)
{
	/*** int형 변수 저장 ***/
	BoundCheckArray<int> iArr(5);
	for (int i = 0; i < 5; i++)
	{
		iArr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << iArr[i] << endl;
	}

	/*** Point 객체 저장 ***/
	BoundCheckArray<Point> pArr(3);
	pArr[0] = Point(3, 4);
	pArr[1] = Point(5, 6);
	pArr[2] = Point(7, 8);
	for (int i = 0; i < pArr.GetArrLen(); i++)
	{
		cout << pArr[i];
	}

	/*** Point 객체의 주소값 저장 ***/
	typedef Point* POINT_PTR;
	BoundCheckArray<POINT_PTR> ppArr(3);
	ppArr[0] = new Point(3, 4);
	ppArr[1] = new Point(5, 6);
	ppArr[2] = new Point(7, 8);
	for (int i = 0; i < ppArr.GetArrLen(); i++)
	{
		cout << *(ppArr[i]);
	}

	delete ppArr[0];
	delete ppArr[1];
	delete ppArr[2];

	return 0;
}