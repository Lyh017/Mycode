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

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    
    //只要队列不为空，查看队尾，队头，出队
    while(!q.empty())
    {
        cout<<"队头是:"<<"姓名:"<<q.front().m_Name<<"年龄:"<<q.front().m_Age<<endl;
        
        cout<<"队尾是:"<<"姓名:"<<q.back().m_Name<<"年龄:"<<q.back().m_Age<<endl;

        q.pop();
    }

    cout<<"队列的大小:"<<q.size()<<endl;
}

int main()
{
    test01();
    return 0;
}