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

// �̷� ��쿡�� dynamic_cast�� ���������� ���� �� ��ȯ�� �õ��ϸ� NULL �����Ͱ� ��ȯ�ȴ�.
// ������ �ð��� �ƴ� ���� �ð���(���α׷��� �������� ���ȿ�) �������� �˻��ϵ��� �����Ϸ��� ���̳ʸ� �ڵ带 �����Ѵ�.
int main(void)
{
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);

	if (comPtr == NULL)
	{
		cout << "�� ��ȯ ����" << endl;
	}
	else
	{
		comPtr->ShowSimpleInfo();
	}

	return 0;
}