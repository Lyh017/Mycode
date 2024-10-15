#include<iostream>
#include<string>
using namespace std;

//ģ��ľ�����
//ģ�岻�����ܵģ�һЩ�ض����������ͣ���Ҫ�þ��廯��ʽ������ʵ��

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    int m_Age;
    string m_Name;
};

//�Ա����������Ƿ���Ⱥ���
template<typename T>
bool myCompare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//���þ��廯Person�汾ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(Person &a,Person &b)
{
    if(a.m_Name==b.m_Name && a.m_Age==b.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a=19;
    int b=20;
    bool ret=myCompare(a,b);
    if(ret)
    {
        cout<<"a = b"<<endl;
    }
    else
    {
        cout<<"a != b"<<endl;
    }
}

void test02()
{
    Person p1("Tom",1);
    Person p2("Tom",10);
    bool ret=myCompare(p1,p2);
    if(ret)
    {
        cout<<"p1 = p2"<<endl;
    }
    else
    {
        cout<<"p1 != p2"<<endl;
    }
}



int main()
{
    //test01();
    test02();
    return 0;
}

//���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
//ѧϰģ�岻��Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��