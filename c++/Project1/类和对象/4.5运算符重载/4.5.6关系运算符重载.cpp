#include<iostream>
#include<string>
using namespace std;


//重载关系运算符
class Person
{
public:
    Person(string name,int age)
    {
        m_Name=name;
        m_Age=age;
    }

    string m_Name;
    int m_Age;

    //重载 == 号
    bool operator==(Person& p)
    {
        if(this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return true;
        }
        else{
            return false;
        }
    }

    //重载 != 号
    bool operator!=(Person& p)
    {
        if(this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        {
            return false;
        }
        else{
            return true;
        }
    }

};


void test01()
{
    Person p1("Tom",18);
    Person p2("Jerey",18);

    if(p1 == p2)
    {
        cout<<"p1和p2相等"<<endl;
    }
    else
    {
        cout<<"p1和p2不相等"<<endl;
    }
}


void test02()
{
    Person p1("Tom",18);
    Person p2("Jerey",18);
    if(p1 != p2)
    {
        cout<<"p1和p2不相等"<<endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}