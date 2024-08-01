#include <iostream>
namespace BestComTmp1
{
	void SimpleFunc(void);
}

namespace ProgComImp1
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComTmp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}

void BestComTmp1::SimpleFunc(void)
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}