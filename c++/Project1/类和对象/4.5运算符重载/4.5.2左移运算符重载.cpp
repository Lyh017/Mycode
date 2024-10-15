#include<iostream>
using namespace std;

//左移运算符重载

class Person
{
public:
    //利用成员函数重载 左移运算符  p.operator<<(cout) 简化版本 p<<cout
    //void operator<<(cout)
    //不会利用成员函数重载<<运算符，因为无法实现 cout在左侧
    
    int m_A;
    int m_B;

};


//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &cout,Person &p)  //本质 operator<< (cout,p)  简化 cout<<p
//返回&，实现链式调用
{
    cout<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B;
    return cout;
}

//重载左移运算符配合友元可以实现输出自定义数据类型

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



















