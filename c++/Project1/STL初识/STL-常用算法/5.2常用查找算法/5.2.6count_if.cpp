#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//count_if ������ͳ��Ԫ�ظ���  ҲҪ�ṩһ��ν��

//ͳ��������������
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

    //ͳ�ƴ���30�ĸ���
    int num=count_if(v.begin(),v.end(),Greater30());
    cout<<"����30������"<<num<<endl;
}

//ͳ���Զ�����������
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

//ν��
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
    //ͳ���������30����
    int num = count_if(v.begin(),v.end(),AgeGreater30());
    cout<<"�������30������"<<num<<"��"<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}