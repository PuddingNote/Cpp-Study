#include "1-1. PointTemplate.h"
#include "1-2. ArrayTemplate.h"
#include <iostream>
using namespace std;

int main(void)
{
	BoundCheckArray<Point<int>> oArr1(3);
	oArr1[0] = Point<int>(3, 4);
	oArr1[1] = Point<int>(5, 6);
	oArr1[2] = Point<int>(7, 8);
	for (int i = 0; i < oArr1.GetArrLen(); i++)
	{
		oArr1[i].ShowPosition();
	}

	BoundCheckArray<Point<double>> oArr2(3);
	oArr2[0] = Point<double>(3.14, 4.31);
	oArr2[1] = Point<double>(5.09, 6.07);
	oArr2[2] = Point<double>(7.82, 8.54);
	for (int i = 0; i < oArr2.GetArrLen(); i++)
	{
		oArr2[i].ShowPosition();
	}

	typedef Point<int>* POINT_PTR;
	BoundCheckArray<POINT_PTR> opArr(3);
	opArr[0] = new Point<int>(11, 12);
	opArr[1] = new Point<int>(13, 14);
	opArr[2] = new Point<int>(15, 16);
	for (int i = 0; i < opArr.GetArrLen(); i++)
	{
		opArr[i]->ShowPosition();
	}

	delete opArr[0];
	delete opArr[1];
	delete opArr[2];

	return 0;
}