#include <iostream>
namespace BestComTmp1
{
	void SimpleFunc(void);
}

namespace BestComTmp1
{
	void PrettyFunc(void);
}

namespace ProgComImp1
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComTmp1::SimpleFunc();

	return 0;
}

void BestComTmp1::SimpleFunc(void)
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc();					// ���� �̸�����
	ProgComImp1::SimpleFunc();		// �ٸ� �̸�����
}

void BestComTmp1::PrettyFunc(void)
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}