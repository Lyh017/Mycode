#include<iostream>
#include<string>
using namespace std;


//类模板的对象做函数参数

template<class T1,class T2>
class Person
{
public:

    Person(T1 name,T2 age)
    {
        m_Name=name;
        m_Age=age;
    }

    void showPerson()
    {
        cout<<"姓名："<<m_Name<<" 年龄："<<m_Age<<endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1.指定传入类型

void printPerson1(Person<string,int>& p)
{
    p.showPerson();
}

void test01()
{
    Person<string,int> p1("张三",16);
    printPerson1(p1);
}


//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>& p)
{
    p.showPerson();
    cout<<"T1的类型为:"<<typeid(T1).name()<<endl;
    cout<<"T2的类型为:"<<typeid(T2).name()<<endl;
}

void test02()
{
    Person<string,int> p1("James",39);
    printPerson2(p1);
}


//3.整个类模板化
template<class T>
void printPerson3(T &p)   //Person类模板化
{
    p.showPerson();
    cout<<"T的类型为:"<<typeid(T).name()<<endl;
}

void test03()
{
    Person<string,int> p1("KD",36);
    printPerson3(p1);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}

