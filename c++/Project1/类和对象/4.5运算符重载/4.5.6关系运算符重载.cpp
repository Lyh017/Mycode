#include<iostream>
#include<string>
using namespace std;


//���ع�ϵ�����
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

    //���� == ��
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

    //���� != ��
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
        cout<<"p1��p2���"<<endl;
    }
    else
    {
        cout<<"p1��p2�����"<<endl;
    }
}


void test02()
{
    Person p1("Tom",18);
    Person p2("Jerey",18);
    if(p1 != p2)
    {
        cout<<"p1��p2�����"<<endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}