#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>


//vector容器存放自定义数据类型
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

void test01()
{
    vector<Person>v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        //cout<<(*it).m_Name<<(*it).m_Age<<endl;
        cout<<it->m_Name<<it->m_Age<<endl;
    }

    
}

//存放自定义数据类型的指针
void test02()
{
    vector<Person*>v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        //cout<<(*it).m_Name<<(*it).m_Age<<endl;
        cout<<(*it)->m_Name<<(*it)->m_Age<<endl;
    }


}

int main()
{
    //test01();
    test02();
    return 0;
}