#include<iostream>
using namespace std;

//��������(�º���)
//����������ʹ��ʱ��������ͨ�����������ã������в����������з���ֵ
//�������󳬳���ͨ�����ĸ����������������Լ���״̬
//�������������Ϊ��������

class MyAdd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};

void test01()
{
    MyAdd add;  //��������
    int ret=add(1,2);
    cout<<"ret="<<ret<<endl;
}

class Myprint
{
public:

    Myprint()
    {
        this->count=0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        count++;
    }

    int count;
};

void test02()
{
    Myprint print;
    print("Hello");
    print("Hello");
    print("Hello");
    print("Hello");
    cout<<"Myprint������"<<print.count<<"��"<<endl;
}

void doPrint(Myprint& p,string st)
{
    p(st);
}
void test03()
{
    Myprint print;
    doPrint(print,"How to be a ML expert?");

}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}