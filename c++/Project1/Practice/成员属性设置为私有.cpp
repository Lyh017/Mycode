#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//��Ա��������˽��
//1.�����Լ����ƶ�дȨ��  2.����д���Լ��������Ч��

class Person
{
public:
	//���з�����˽�����Կ���
	void SetName(string name)
	{
		m_Name = name;
	}
	string GetName()
	{
		return m_Name;
	}
	int getAge()
	{
		return m_Age;
	}
	//��������
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "�����������󣬸�ֵʧ��" << endl;
			return;
		}
		else
		{
			m_Age = age;
		}
		
	}
private:
	string m_Name; //�������ɶ���д
	int m_Age = 18; //���䣬ֻ��  Ҳ����д��������0��150֮�䣩
	string m_Idol; //ż��ֻд
};


int main()
{
	Person p;
	p.SetName("Zhangsan");
	p.setAge(16);
	cout << "����: " << p.GetName() << endl;
	cout << "���䣺" << p.getAge() << endl; //��ȡ����

	return 0;
}