#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1.���캯���ķ��༰����
//����
//���ղ������� �޲ι���(Ĭ�Ϲ���)���вι���
//�������ͷ��� ��ͨ����  ��������
class Person
{
public:
	Person()
	{
		cout << "Person���޲ι��캯���ĵ���" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯���ĵ���" << endl;
	}
	
	//�������캯��
	Person(const Person &p)
	{
		age = p.age;   //������������ϵ��������ԣ�������������
		cout << "Person�Ŀ������캯���ĵ���" << endl;
	}

	~Person()
	{
		cout << "Person�����������ĵ���" << endl;
	}
	int age;
};

//����
void test01()
{
	//1.���ŷ�
	//Person p1;  //Ĭ�Ϲ��캯������

	//Person p2(10);   //�вι��캯��

	//Person p3(p2);   //�������캯��

	//ע������1
	//����Ĭ�Ϲ��캯����ʱ��Ҫ�ӣ���,����������Ϊ����һ��������������������Ϊ�ڴ�������


	
	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p3.age << endl;

	//2.��ʾ��

	Person p1;
	Person p2 = Person(10);  //�вι��� Person(10����һ�����������ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
	Person p3 = Person(p2);  //��������

	//ע������2
	//��Ҫ���ÿ������캯�� ��ʼ����������,����������ΪPerson(p3) == Person p3;
	//Person(p3);
	

	//3.��ʽת����
	Person p4 = 10;  //�൱��д��Person p4 = Person(10)
	Person p5 = p4;
}

int main()
{
	test01();
	return 0;
}