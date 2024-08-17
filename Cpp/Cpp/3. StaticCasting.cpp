#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;

public:
	Car(int fuel) : fuelGauge(fuel)
	{

	}
	void ShowCarState()
	{
		cout << "잔여 연료랑: " << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
	{

	}
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

// static_cast<T>(expr);
// 유도 -> 기초 , 기초 -> 유도 모두 OK 하지만 책임은 본인이 져야함
// 보다 많은 형변환 허용 / 책임이 따름
// 허용 정도 : C언어 형변환 >> static_cast<T>(expr) >> dynamic_cast<T>(expr)
int main(void)
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);	// 컴파일 OK
	ptruck1->ShowTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);	// 컴파일 OK 그러나 이 경우엔 책임을 지지 못한 경우
	ptruck2->ShowTruckState();
	cout << endl;

	return 0;
}