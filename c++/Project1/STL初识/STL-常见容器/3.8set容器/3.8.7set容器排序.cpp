#include<iostream>
#include<string>
using namespace std;
#include<set>

//set����������

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

    //ָ���������Ӵ�С
    set<int,MyCompare>s2;  //ģ������б�Ҫ��һ������
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

//set����Զ�����������

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
    //�Զ�����������Ͷ���ָ���������

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
        cout<<"������"<<it->m_Name<<" ���䣺"<<it->m_Age<<endl;
    }
    
    for(const auto&person : s)    //��Χѭ���﷨
    {
        cout<<"������"<<person.m_Name<<" ���䣺"<<person.m_Age<<endl;
    }

    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<"������"<<it->m_Name<<" ���䣺"<<it->m_Age<<endl;
    }

}

int main()
{
    //test01();
    test02();
    return 0;
}