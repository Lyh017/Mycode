#include<iostream>
using namespace std;

//�̳���ͬ����Ա����
class Base
{
public:
    Base()
    {
        m_A=100;
    }

    void func()
    {
        cout<<"Base����func()����"<<endl;
    }

    void func(int a)
    {
        cout<<"Base����func(int a)����"<<endl;
    }

    int m_A;
};

class Son : public Base
{
public:

    int m_A;

    Son()
    {
        m_A=200;
    }

    void func()
    {
        cout<<"Son����func()����"<<endl;
    }


};

//ͬ����Ա����
void test01()
{
    Son s;
    cout<<"Son��m_A = "<<s.m_A<<endl;
    cout<<"Base��m_A = "<<s.Base::m_A<<endl;
    //���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
}

//ͬ����Ա����
void test02()
{
    Son s;
    s.func();
    s.Base::func();
    //ͬ��ҲҪ��������

    s.Base::func(10); //��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա���������ص�����������ͬ����Ա����������������Ҫ��������
}


int main()
{
    //test01();
    test02();
    return 0;
}