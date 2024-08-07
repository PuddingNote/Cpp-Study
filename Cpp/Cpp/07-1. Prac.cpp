// ���� 1
//#include <iostream>
//using namespace std;
//
//class Car	// �⺻ ���� �ڵ���
//{
//private:
//	int gasolineGauge;
//
//public:
//	Car(int gas) : gasolineGauge(gas)
//	{
//
//	}
//	int GetGasGauge()
//	{
//		return gasolineGauge;
//	}
//};
//
//class HybridCar : public Car	// ���̺긮�� �ڵ���
//{
//private:
//	int electricGauge;
//
//public:
//	HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
//	{
//
//	}
//	int GetElecGauge()
//	{
//		return electricGauge;
//	}
//};
//
//class HybridWaterCar : public HybridCar	// ���̺긮�� ����ī
//{
//private:
//	int waterGauge;
//
//public:
//	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
//	{
//
//	}
//	void ShowCurrentGauge()
//	{
//		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
//		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
//		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
//	}
//};
//
//int main(void)
//{
//	HybridWaterCar hwc(10, 20, 30);
//	hwc.ShowCurrentGauge();
//
//	return 0;
//}

// ���� 2
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;

public:
	MyFriendInfo(const char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[] name;
		cout << "~MyFriendInfo()" << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone) : MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);

		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
		cout << "~MyFriendDetailInfo()" << endl;
	}
};

int main(void)
{
	MyFriendDetailInfo f1("HAN", 20, "ADDR1", "010-1111-2222");
	f1.ShowMyFriendDetailInfo();

	MyFriendDetailInfo f2("CHAN", 25, "ADDR2", "010-2222-3333");
	f2.ShowMyFriendDetailInfo();

	return 0;
}