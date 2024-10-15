#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list������������ �����Զ����������� ������
//������������������������ͬ������߽��н���

class Person
{
public:
    string m_Name; //����
    int m_Age;   //����
    int m_Height;   //���

    Person(string name,int age,int height)
    {
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
};

//ָ���������
bool comparePerson(Person& p1,Person& p2)
{
    //������������
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
        cout<<"������"<<(*it).m_Name<<" ���䣺"<<(*it).m_Age<<" ��ߣ�"<<(*it).m_Height<<endl;
    }

    //����
    cout<<"----------------------------------"<<endl;
    cout<<"�����:"<<endl;

    L.sort(comparePerson);
    
    for(list<Person>::iterator it=L.begin();it!=L.end();it++)
    {
        cout<<"������"<<(*it).m_Name<<" ���䣺"<<(*it).m_Age<<" ��ߣ�"<<(*it).m_Height<<endl;
    }
}

int main()
{
    test01();
    return 0;
}