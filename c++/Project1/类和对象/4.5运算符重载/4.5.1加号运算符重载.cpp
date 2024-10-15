#include<iostream>
using namespace std;

//加号运算符重载
//1.成员函数重载 + 
//2.全局函数重载


//成员函数重载本质调用
//Person p3=p1.operator+(p2);

class Person
{
public:

    // Person operator+(Person &p)  //成员函数重载 +
    // {
    //     Person temp;
    //     temp.m_A=this->m_A+p.m_A;
    //     temp.m_B=this->m_B+p.m_B;

    //     return temp;

    // }

    int m_A;
    int m_B;


};


//全局函数重载+号
//全局函数重载的本质调用  Person p3 = operator+(p1,p2)
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}

//运算符重载也可以发生函数重载
//函数重载的版本
Person operator+(Person &p,int num)
{
    Person temp;
    temp.m_A=p.m_A+num;
    temp.m_B=p.m_B+num;
    
    return temp;
}



void test01()
{
    Person p1;
    p1.m_A=10;
    p1.m_B=10;

    Person p2;
    p2.m_A=10;
    p2.m_B=10;

    Person p3 = p1 + p2;

    Person p4=p1+300;

    cout<<"p3.m_A = "<<p3.m_A<<endl;
    cout<<"p3.m_B = "<<p3.m_B<<endl;

    cout<<"p4.m_A = "<<p4.m_A<<endl;
    cout<<"p4.m_B = "<<p4.m_B<<endl;
}

void test02()
{
    Person p1;
    p1.m_A=20;
    p1.m_B=10;

    Person p2;
    p2.m_A=20;
    p2.m_B=10;

    Person p3=p1+p2;
    cout<<"p3.m_A = "<<p3.m_A<<endl;
    cout<<"p3.m_B = "<<p3.m_B<<endl;

}

int main()
{

    test01();
    //test02();
    return 0;
}