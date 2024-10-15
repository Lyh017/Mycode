#include<iostream>
using namespace std;
#include <string>

//��ǰ�ñ�����֪��Person��
template<class T1,class T2>
class Person;
//����ʵ��
template<class T1,class T2>
void printPerson2(Person<T1,T2> p)
{
    cout<<"����ʵ�֡���������"<<p.m_Name<<" ���䣺"<<p.m_Age<<endl;
}
//ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ

template<class T1,class T2>
class Person
{
    //ȫ�ֺ�������ʵ��
    friend void printPerson(Person<T1,T2> p)
    {
        cout<<"������"<<p.m_Name<<" ���䣺"<<p.m_Age<<endl;
    }

    //ȫ�ֺ�������ʵ��
    //�ӿ�ģ������б�
    //���ȫ�ֺ��� ������ʵ�� ��Ҫ�ñ�������ǰ֪����������Ĵ���
    friend void printPerson2<>(Person<T1,T2> p);
    

public:

    Person(T1 name,T2 age)
    {
        m_Name=name;
        m_Age=age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};



//1.ȫ�ֺ���������ʵ��
void test01()
{
    Person<string,int> p1("Tom",10);
    printPerson(p1);
}

//2.ȫ�ֺ���������ʵ��
void test02()
{
    Person<string,int> p2("Jerry",10);
    printPerson2(p2);
}

int main()
{
    test01();
    test02();
    return 0;
}