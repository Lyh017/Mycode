#include<iostream>
using namespace std;

//��̬��Ա����
//1.���ж�����ͬһ������
//2.�ڱ���׶η����ڴ�
//3.���������������ʼ��

//��̬��Ա����Ҳ���з���Ȩ�޵�

class Person
{
public:
    static int m_A;

private:
    static int m_B;
};

int Person :: m_A = 10;
int Person :: m_B = 100;


void test01()
{
    Person p;
    cout<<p.m_A<<endl;

    Person p2;
    p2.m_A=2000;
    cout<<p2.m_A<<endl;
}

//��̬��Ա������������ĳ�������ϣ����ж��󶼹���ͬһ������
//��˾�̬��Ա���������ַ��ʷ�ʽ
//1.ͨ���������
//2.ͨ���������з���

void test02()
{
    // Person p;
    // cout<<p.m_A<<endl;
    cout<<Person::m_A<<endl;

    //cout<<Person::m_B<<endl; ������ʲ���˽�о�̬��Ա���� 
}


//��̬��Ա����
//1.���ж�����ͬһ������
//2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
//3.Ҳ�з���Ȩ��,������ʲ���˽�еľ�̬��Ա����
class Person2
{
public:
    //��̬��Ա����
    static void func()
    {
        m_A=100;
        //m_B=200;  ��̬��Ա�������ɷ��ʷǾ�̬��Ա�������޷����ֵ������ĸ������m_B������
        cout<<"static void func����"<<endl;
    }

    static int m_A; //��̬��Ա����
    int m_B;

private:
    static void func2()
    {

    }
};

int Person2::m_A=10;

void test03()
{
    //1.ͨ���������
    // Person2 p;
    // p.func();

    //2.ͨ����������
    Person2::func();
}



int main()
{
    test01();
    //test02();
    //test03();

    return 0;
}