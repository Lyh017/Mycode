#include<iostream>
using namespace std;

//继承中同名成员处理
class Base
{
public:
    Base()
    {
        m_A=100;
    }

    void func()
    {
        cout<<"Base——func()调用"<<endl;
    }

    void func(int a)
    {
        cout<<"Base——func(int a)调用"<<endl;
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
        cout<<"Son——func()调用"<<endl;
    }


};

//同名成员属性
void test01()
{
    Son s;
    cout<<"Son下m_A = "<<s.m_A<<endl;
    cout<<"Base下m_A = "<<s.Base::m_A<<endl;
    //如果通过子类对象 访问到父类中同名成员，需要加作用域
}

//同名成员函数
void test02()
{
    Son s;
    s.func();
    s.Base::func();
    //同样也要加作用域

    s.Base::func(10); //如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有同名成员函数，如果想访问需要加作用域
}


int main()
{
    //test01();
    test02();
    return 0;
}