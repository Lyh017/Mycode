#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    int m_Age;
    string m_Name;
};
void test01()
{
    queue<Person>q;

    Person p1("Mike",10);
    Person p2("Jerey",20);
    Person p3("Johnson",40);
    Person p4("Jordan",49);

    //���
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    
    //ֻҪ���в�Ϊ�գ��鿴��β����ͷ������
    while(!q.empty())
    {
        cout<<"��ͷ��:"<<"����:"<<q.front().m_Name<<"����:"<<q.front().m_Age<<endl;
        
        cout<<"��β��:"<<"����:"<<q.back().m_Name<<"����:"<<q.back().m_Age<<endl;

        q.pop();
    }

    cout<<"���еĴ�С:"<<q.size()<<endl;
}

int main()
{
    test01();
    return 0;
}