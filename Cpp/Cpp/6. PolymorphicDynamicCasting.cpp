#include <iostream>
using namespace std;

class SoSimple	// Polymorphic Ŭ���� : �ϳ� �̻��� �����Լ��� ���ϴ� Ŭ����
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
	void ShowSimpleInfo()	// �̰͵� �����Լ�
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

// ���� Ŭ������ Polymorphic Ŭ�����̸� dynamic_cast�� ���� -> ������ ����ȯ ����
// �׷� �̷��� dynamic_cast�� static_cast�� ���̴� ���� - ��������
int main(void)
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();

	return 0;
}