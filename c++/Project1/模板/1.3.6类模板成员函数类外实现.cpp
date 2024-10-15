#include<iostream>
#include<string>
using namespace std;


//��ģ���Ա��������ʵ��
template<class T1,class T2>
class Person
{
public:

    Person(T1 name,T2 age);
    // {
    //     this->m_Age=age;
    //     this->m_Name=name;
    // }

    void showPerson();
    // {
    //     cout<<"������"<<this->m_Name<<" ���䣺"<<this->m_Age<<endl;
    // }

    T1 m_Name;
    T2 m_Age;
};

//���캯��������ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->m_Age=age;
    this->m_Name=name;
}

//��Ա����������ʵ��
template<class T1,class T2>
void Person<T1,T2> :: showPerson()
{
    cout<<"������"<<this->m_Name<<" ���䣺"<<this->m_Age<<endl;
}

void test01()
{
    Person<string,int> p1("Frank",43);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}


