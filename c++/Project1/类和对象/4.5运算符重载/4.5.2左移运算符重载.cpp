#include<iostream>
using namespace std;

//�������������

class Person
{
public:
    //���ó�Ա�������� ���������  p.operator<<(cout) �򻯰汾 p<<cout
    //void operator<<(cout)
    //�������ó�Ա��������<<���������Ϊ�޷�ʵ�� cout�����
    
    int m_A;
    int m_B;

};


//ֻ������ȫ�ֺ����������������
ostream & operator<<(ostream &cout,Person &p)  //���� operator<< (cout,p)  �� cout<<p
//����&��ʵ����ʽ����
{
    cout<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B;
    return cout;
}

//������������������Ԫ����ʵ������Զ�����������

void test01()
{
    Person p;
    p.m_A=10;
    p.m_B=10;

    cout<<p<<endl;
    
}



int main()
{
    test01();
    return 0;

}



















