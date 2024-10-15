#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//find_if 按条件查找元素 
//查找内置数据类型

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};

void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    auto it=find_if(v.begin(),v.end(),GreaterFive());  //第三个参数是谓词，(返回bool类型的仿函数)即查找的条件
    if(it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到大于5的数为"<<*it<<endl;
    }
}

//查找自定义数据类型
class Person
{
public:
    string m_Name;
    int m_Age;

    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
};

class Greater20
{
public:
    bool operator()(const Person& p)
    {
        if(p.m_Age>20)
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
    vector<Person>v2;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("FFF",50);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);
    //找年龄大于20的
    auto it=find_if(v2.begin(),v2.end(),Greater20());
    if(it==v2.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到年龄大于20的人"<<it->m_Name<<it->m_Age<<endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}