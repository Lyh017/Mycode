#include<iostream>
#include<string>
using namespace std;

//类对象作为类成员

class Phone
{
public:

    Phone(string pName)
    {
        m_PName=pName;
        cout<<"Phone的构造函数的调用"<<endl;
    }

    string m_PName;

    ~Phone()
    {
        cout<<"Phone的析构函数的调用"<<endl;
    }
};


class Person
{
public:

    Person(string name,string pName):m_Name(name),m_Phone(pName) //Phone m_Phone = pName 隐式转换法
    {
        cout<<"Person的构造函数调用"<<endl;
    }
    //姓名
    string m_Name;

    //手机
    Phone m_Phone;

    ~Person()
    {
        cout<<"Person的析构函数调用"<<endl;
    }
};

void test01()
{
    Person p("张三","iPhone 15 promax");
    cout<<p.m_Name<<"拿着："<<p.m_Phone.m_PName<<endl;

}
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构相反

int main()
{
    test01();
    return 0;
}


















