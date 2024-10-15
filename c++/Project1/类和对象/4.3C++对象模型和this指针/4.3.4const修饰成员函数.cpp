#include<iostream>
using namespace std;


//常函数
class Person
{
public:
    //this指针的本质 是指针常量 指针的指向是不可修改的(地址)
    //const Person* const this  前面再加一个const,指针指向的值也不能改
    //在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const
    {   
        m_B=10;
        //m_A=100;
       // this=NULL; this指针不可以修改指针的指向,地址不能修改
       cout<<m_B<<endl;
    }

    void func() {}

    int m_A=0;
    mutable int m_B=0; //特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
};

//常对象
void test02()
{
    const Person p;  //在对象前加const，常对象不能修改本身属性
    p.m_B=100;  //m_B是特殊值，常对象下也可以改

    //常对象只能调用常函数
    p.showPerson();
    //p.func();
}


int main()
{
    test02();
    return 0;
}