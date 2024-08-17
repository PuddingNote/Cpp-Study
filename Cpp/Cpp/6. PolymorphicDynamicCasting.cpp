#include <iostream>
using namespace std;

class SoSimple	// Polymorphic 클래스 : 하나 이상의 가상함수를 지니는 클래스
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()	// 이것도 가상함수
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

// 기초 클래스가 Polymorphic 클래스이면 dynamic_cast도 기초 -> 유도로 형변환 가능
// 그럼 이럴때 dynamic_cast와 static_cast의 차이는 뭘까 - 다음예제
int main(void)
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();

	return 0;
}