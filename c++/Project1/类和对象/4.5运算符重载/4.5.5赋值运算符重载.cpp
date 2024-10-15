#include<iostream>
using namespace std;

//赋值运算符重载
class Person
{
public:
    int* m_Age;

    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if(m_Age!=NULL)  
        {
            delete m_Age;
            m_Age=NULL;
        }
        
    }

    //重载赋值运算符
    Person& operator=(Person& p)
    {
        //编译器提供浅拷贝 m_Age=p.m_Age
        //堆区内存重复释放
        //应该先判断是否有属性在堆区，如果有先释放，再深拷贝
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        //深拷贝
        m_Age = new int(*p.m_Age);

        return *this;

    }
};


void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);



    p3=p2=p1; 

    cout<<"p1年龄为："<<*p1.m_Age<<endl;
    cout<<"p2年龄为："<<*p2.m_Age<<endl;
    cout<<"p3年龄为："<<*p3.m_Age<<endl;
    

    

}


int main()
{
    test01();
    return 0;
}