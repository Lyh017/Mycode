#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//���һ��Բ�࣬��Բ���ܳ�
class Circle
{
public:

	//����
	int m_r;

	//��Ϊ
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
		cout << "������" << name << " ѧ�ţ�" << ID << endl;
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
		m_Name = "����";
		m_Car = "Audi";
		m_Password = 12345;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "����";
	//p1.m_Car = "����";  ������ʲ���
}

