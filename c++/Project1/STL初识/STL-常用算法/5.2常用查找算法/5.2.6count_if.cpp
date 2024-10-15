#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//count_if 按条件统计元素个数  也要提供一个谓词

//统计内置数据类型
class Greater30
{
public:
    bool operator()(int val)
    {
        return val>30;
    }
};
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    v.push_back(60);
    v.push_back(50);

    //统计大于30的个数
    int num=count_if(v.begin(),v.end(),Greater30());
    cout<<"大于30的数有"<<num<<endl;
}

//统计自定义数据类型
class Person
{
public:
    int m_Age;
    string m_Name;
    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
};

//谓词
class AgeGreater30
{
public:
    bool operator()(const Person& p)
    {
        if(p.m_Age>30)
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
    Person p5("Luka",25);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //统计年龄大于30的人
    int num = count_if(v.begin(),v.end(),AgeGreater30());
    cout<<"年龄大于30的人有"<<num<<"个"<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}