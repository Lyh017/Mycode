#include<iostream>
using namespace std;

//������
class Animal
{
public:
    int m_Age;
};

//������̳� ������μ̳�����
//�̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
//Animal���Ϊ�����
//����
class Sheep : virtual public Animal{};

//����
class Camel : virtual public Animal{};

//������
class Alpaca : public Sheep,public Camel
{

};

void test01()
{
    Alpaca ac;
    ac.Sheep::m_Age=18;
    ac.Camel::m_Age=28;
    //���������μ̳е�ʱ����������ӵ����ͬ���ݣ���Ҫ������������
    cout<<"ac.Sheep::m_Age = "<<ac.Sheep::m_Age<<endl;
    cout<<"ac.Camel::m_Age = "<<ac.Camel::m_Age<<endl;
    //cout<<ac.m_Age<<endl; Ҳ����

    //�����������֪��ֻҪ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�

}

int main()
{
    test01();
    return 0;
}