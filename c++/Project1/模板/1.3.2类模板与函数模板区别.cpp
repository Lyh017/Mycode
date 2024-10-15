#include<iostream>
#include<string>
using namespace std;

//类模板与函数模板区别
template<class NameType,class AgeType=int>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        m_Age=age;
        m_Name=name;
    }

    void showPerson()
    {
        cout<<"name = "<<m_Name<<" age = "<<m_Age<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

//类模板没有自动类型推导使用方式
void test01()
{
    //Person p("Maker",10);  //无法推导类模板参数
    Person<string,int> p("Maker",10); //只能用显示指定类型
    p.showPerson();
}


//类模板在模板参数列表中可以有默认参数
void test02()
{
    Person<string> p1("Tony",20);
    p1.showPerson();

}


int main()
{
    //test01();
    test02();
    return 0;
}