#include<iostream>
using namespace std;

//���캯���ĵ��ù���
//1.����һ���࣬c++���������ÿ���඼���������������
//Ĭ�Ϲ��죨��ʵ�֣�
//������������ʵ�֣�
//�������죨ֵ������


//2.���д���вι��캯�����������Ͳ����ṩĬ�Ϲ��죬��Ȼ�ṩ��������


//3.���д�˿������캯���������������ṩ��������ͨ���캯��
class Person
{
public:
    Person()
    {
        cout<<"PersonĬ�Ϲ��캯������"<<endl;
    }

    Person(int age)
    {
        cout<<"Person�вι��캯������"<<endl;
        m_Age=age;
    }

    Person(const Person &p)
    {
        cout<<"Person�������캯������"<<endl;
        m_Age=p.m_Age;
    }

    ~Person()
    {
        cout<<"Person������������"<<endl;

    }

    int m_Age;
};

void test01()
{
    Person p;
    p.m_Age=18;
    Person p2(p);

    cout<<"p2������Ϊ��"<<p2.m_Age<<endl;
}


void test02()
{
    Person p(28);
    Person p2(p);
    cout<<"p2������Ϊ��"<<p2.m_Age<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}