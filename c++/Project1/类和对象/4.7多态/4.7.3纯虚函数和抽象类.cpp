#include<iostream>
using namespace std;


//���麯���ͳ�����
class Base
{
public:

    virtual void func() = 0; //���麯��
    //ֻҪ��һ�����麯����������Ϊ������

    //�������ص�:
    //1.�޷�ʵ��������
    //2. ����������� ����Ҫ��д�����еĴ��麯�� ����Ҳ���ڳ�����
};

class Son : public Base
{
public:

    void func()
    {
        cout<<"func��������"<<endl;
    }

};


void test01()
{
    Base* base = new Son;
    base->func();
}



int main()
{
    test01();
    return 0;
}