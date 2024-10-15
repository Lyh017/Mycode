#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list容器，排序案例 对于自定义数据类型 做排序
//按照年龄进行升序，如果年龄相同按照身高进行降序

class Person
{
public:
    string m_Name; //姓名
    int m_Age;   //年龄
    int m_Height;   //身高

    Person(string name,int age,int height)
    {
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
};

//指定排序规则
bool comparePerson(Person& p1,Person& p2)
{
    //按照年龄升序
    if(p1.m_Age==p2.m_Age)
    {
        return p1.m_Height>p2.m_Height;
    }
    else
    {
        return p1.m_Age<p2.m_Age;
    } 
}

void test01()
{
    list<Person> L;
    Person p1("Durant",36,210);
    Person p2("James",40,203);
    Person p3("Curry",35,191);
    Person p4("Paul",39,183);
    Person p5("Conley",36,185);
    Person p6("Miller",36,195);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for(list<Person>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<"姓名："<<(*it).m_Name<<" 年龄："<<(*it).m_Age<<" 身高："<<(*it).m_Height<<endl;
    }

    //排序
    cout<<"----------------------------------"<<endl;
    cout<<"排序后:"<<endl;

    L.sort(comparePerson);
    
    for(list<Person>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<"姓名："<<(*it).m_Name<<" 年龄："<<(*it).m_Age<<" 身高："<<(*it).m_Height<<endl;
    }
}

int main()
{
    test01();
    return 0;
}