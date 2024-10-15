#include<iostream>
#include<string>
using namespace std;
#include<set>

//set容器的排序

class MyCompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
    
};

void test01()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(90);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);

    for(set<int>::iterator it=s1.begin();it!=s1.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

    //指定排序规则从大到小
    set<int,MyCompare>s2;  //模板参数列表要放一个类型
    s2.insert(10);
    s2.insert(40);
    s2.insert(90);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

    for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

}

//set存放自定义数据类型

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    string m_Name;
    int m_Age;
};

class compare
{
public:
    bool operator()(const Person& p1,const Person& p2)
    {
        return p1.m_Age>p2.m_Age;
    }
};

void test02()
{
    //自定义的数据类型都会指定排序规则

    set<Person,compare>s;
    Person p1("Durant",36);
    Person p2("James",40);
    Person p3("Curry",35);
    Person p4("Paul",39);
    Person p5("Conley",36);
    Person p6("Miller",33);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    s.insert(p6);

    for(set<Person,compare>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<endl;
    }
    
    for(const auto&person : s)    //范围循环语法
    {
        cout<<"姓名："<<person.m_Name<<" 年龄："<<person.m_Age<<endl;
    }

    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<endl;
    }

}

int main()
{
    //test01();
    test02();
    return 0;
}