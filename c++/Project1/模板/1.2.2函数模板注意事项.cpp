#include<iostream>
using namespace std;


//����ģ��ע������
//1.�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
//2.ģ�����Ҫȷ����T���������Ͳſ���ʹ��

template<typename T>  //typename�����滻��class
void mySwap(T& a,T& b)
{
    
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a=10;
    int b=20;
    //char c='c';
    //mySwap(a,c);  �����Ƶ�����һ�µ�T����
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}
template<typename T>
void func()
{
    cout<<"func�����ĵ���"<<endl;
}

void test02()
{
    func<int>();  //��Ȼ������û��ʹ��T,���Ǳ���Ҫ��Tһ�����Ͳſ���ʹ�ø�ģ��
}

int main()
{
    test01();
    return 0;
}