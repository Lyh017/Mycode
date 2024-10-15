#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
using namespace std;

//int main()
//{
//	int* p1, *p2;
//	p1 = new int(10);
//	p2 = new int[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p2 + i) = i;
//	}
//	cout << *p1 << endl;
//	for (int j = 0; j < 10; j++)
//	{
//		cout << *(p2 + j) << " ";
//	}
//	cout << endl;
//	for (i = 0; i < 10; i++)
//	{
//		cout << p2[i] << " ";
//	}
//	cout << endl;
//	delete p1;
//	delete[]p2;
//	return 0;
//}
//Car::Car()
//{
//	color = "red";
//}
//
//int main()
//{
//	Car car1;
//	car1.setColor("blue");
//	Car car2;
//	//car2.setColor("black");
//	car1.setRegistration(12345);
//	car2.setRegistration(67890);
//	Car* car3 = new Car;
//	car3->setColor("pink");
//	cout << "car3 color is " << car3->getColor() << endl;
//	cout << "car1 color is " << car1.getColor()<< endl;
//	cout << "car2 color is " << car2.color << endl;
//	cout << "car1 registration is " << car1.getRegistration() << endl;
//	delete car3;
//	return 0;
//}


int main()
{
	int a = 10;
	int& b = a;
	cout << &a << endl;
	cout << &b << endl;
	return 0;
}
