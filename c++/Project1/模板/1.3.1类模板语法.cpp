#include<iostream>
#include<string>
using namespace std;

//ÀàÄ£°å
template<class NameType,class AgeType>
class Person
{
public:

    Person(NameType name,AgeType age)
    {
        m_Age=age;
        m_Name=name;
    }

    void showPerson()
    {
        cout<<"name = "<<m_Name<<endl;
        cout<<"age = "<<m_Age<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};


void test01()
{
    Person<string,int> p1("Tom",18);
    p1.showPerson();
}


int main()
{
    test01();
    return 0;
}