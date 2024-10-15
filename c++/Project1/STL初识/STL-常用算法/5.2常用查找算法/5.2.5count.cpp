#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//常用查找算法count 统计元素出现次数

//1.统计内置数据类型
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);

    int num=count(v.begin(),v.end(),40);
    cout<<"40的元素个数为"<<num<<endl;
}

//2.统计自定义数据类型
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

    bool operator==(const Person& p)
    {
        if(this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test02()
{
    vector<Person>v;
    Person p1("Curry",35);
    Person p2("James",39);
    Person p3("Durant",35);
    Person p4("Tom",35);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    int num=count(v.begin(),v.end(),p4);
    cout<<"和Tom同龄的人的个数为:"<<num<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}