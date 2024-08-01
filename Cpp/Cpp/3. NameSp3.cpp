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
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();					// 동일 이름공간
	ProgComImp1::SimpleFunc();		// 다른 이름공간
}

void BestComTmp1::PrettyFunc(void)
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}