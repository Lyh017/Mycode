#include<iostream>
using namespace std;

//深拷贝与浅拷贝

class Person
{
public:
    Person()
    {
        cout<<"Person默认构造函数调用"<<endl;
    }

    Person(int age,int height)
    {
        cout<<"Person有参构造函数调用"<<endl;
        m_Age=age;
        m_Height = new int(height);
    }

    //自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout<<"Person拷贝构造函数调用"<<endl;
        m_Age=p.m_Age;
        //m_Height=p.m_Height 编译器默认实现就是这样
        //深拷贝操作

        m_Height=new int(*p.m_Height);
    }

    ~Person()
    {
        //析构代码，将堆区开辟的数据释放
        cout<<"Person析构函数调用"<<endl;
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height=NULL;
        }
        //浅拷贝带来的问题就是堆区内存重复释放
    }

    int m_Age;
    int* m_Height;
};

void test01()
{
    Person p1(18,170);
    cout<<"p1的年龄为："<<p1.m_Age<<"身高为："<<*(p1.m_Height)<<endl;

    Person p2(p1);   //如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
    cout<<"p2的年龄为："<<p2.m_Age<<"身高为："<<*(p2.m_Height)<<endl;
}


int main()
{
    test01();

    system("pause");
    return 0;
}