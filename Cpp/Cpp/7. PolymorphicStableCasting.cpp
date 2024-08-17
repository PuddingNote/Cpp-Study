#include <iostream>
using namespace std;

class SoSimple
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
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

// 이런 경우에서 dynamic_cast는 안정적이지 못한 형 변환을 시도하면 NULL 포인터가 반환된다.
// 컴파일 시간이 아닌 실행 시간에(프로그램이 실행중인 동안에) 안정성을 검사하도록 컴파일러가 바이너리 코드를 생성한다.
int main(void)
{
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);

	if (comPtr == NULL)
	{
		cout << "형 변환 실패" << endl;
	}
	else
	{
		comPtr->ShowSimpleInfo();
	}

	return 0;
}