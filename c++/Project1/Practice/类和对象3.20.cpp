#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//设计一个圆类，求圆的周长
class Circle
{
public:

	//属性
	int m_r;

	//行为
	double calcualate()
	{
		return 2 * 3.14 * m_r;
	}
};

class Student
{
public:
	string name;
	int ID;

	void showStudent()
	{
		cout << "姓名：" << name << " 学号：" << ID << endl;
	}

};

class Person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "Audi";
		m_Password = 12345;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";  类外访问不到
}

