#include<iostream>
#include<string>
using namespace std;

//模板的局限性
//模板不是万能的，一些特定的数据类型，需要用具体化方式做特殊实现

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    int m_Age;
    string m_Name;
};

//对比两个数据是否相等函数
template<typename T>
bool myCompare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//利用具体化Person版本实现代码，具体化优先调用
template<> bool myCompare(Person &a,Person &b)
{
    if(a.m_Name==b.m_Name && a.m_Age==b.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a=19;
    int b=20;
    bool ret=myCompare(a,b);
    if(ret)
    {
        cout<<"a = b"<<endl;
    }
    else
    {
        cout<<"a != b"<<endl;
    }
}

void test02()
{
    Person p1("Tom",1);
    Person p2("Tom",10);
    bool ret=myCompare(p1,p2);
    if(ret)
    {
        cout<<"p1 = p2"<<endl;
    }
    else
    {
        cout<<"p1 != p2"<<endl;
    }
}



int main()
{
    //test01();
    test02();
    return 0;
}

//利用具体化的模板，可以解决自定义类型的通用化
//学习模板不是为了写模板，而是在STL能够运用系统提供的模板