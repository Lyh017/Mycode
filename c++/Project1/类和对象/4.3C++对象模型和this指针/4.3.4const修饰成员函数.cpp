#include<iostream>
using namespace std;


//������
class Person
{
public:
    //thisָ��ı��� ��ָ�볣�� ָ���ָ���ǲ����޸ĵ�(��ַ)
    //const Person* const this  ǰ���ټ�һ��const,ָ��ָ���ֵҲ���ܸ�
    //�ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
    void showPerson() const
    {   
        m_B=10;
        //m_A=100;
       // this=NULL; thisָ�벻�����޸�ָ���ָ��,��ַ�����޸�
       cout<<m_B<<endl;
    }

    void func() {}

    int m_A=0;
    mutable int m_B=0; //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable
};

//������
void test02()
{
    const Person p;  //�ڶ���ǰ��const�����������޸ı�������
    p.m_B=100;  //m_B������ֵ����������Ҳ���Ը�

    //������ֻ�ܵ��ó�����
    p.showPerson();
    //p.func();
}


int main()
{
    test02();
    return 0;
}