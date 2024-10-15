#include<iostream>
using namespace std;

//静态成员变量
//1.所有对象共享同一份数据
//2.在编译阶段分配内存
//3.类内声明，类外初始化

//静态成员变量也是有访问权限的

class Person
{
public:
    static int m_A;

private:
    static int m_B;
};

int Person :: m_A = 10;
int Person :: m_B = 100;


void test01()
{
    Person p;
    cout<<p.m_A<<endl;

    Person p2;
    p2.m_A=2000;
    cout<<p2.m_A<<endl;
}

//静态成员变量，不属于某个对象上，所有对象都共享同一份数据
//因此静态成员变量有两种访问方式
//1.通过对象访问
//2.通过类名进行访问

void test02()
{
    // Person p;
    // cout<<p.m_A<<endl;
    cout<<Person::m_A<<endl;

    //cout<<Person::m_B<<endl; 类外访问不到私有静态成员变量 
}


//静态成员函数
//1.所有对象共享同一个函数
//2.静态成员函数只能访问静态成员变量
//3.也有访问权限,类外访问不到私有的静态成员函数
class Person2
{
public:
    //静态成员函数
    static void func()
    {
        m_A=100;
        //m_B=200;  静态成员函数不可访问非静态成员变量，无法区分到底是哪个对象的m_B的属性
        cout<<"static void func调用"<<endl;
    }

    static int m_A; //静态成员变量
    int m_B;

private:
    static void func2()
    {

    }
};

int Person2::m_A=10;

void test03()
{
    //1.通过对象访问
    // Person2 p;
    // p.func();

    //2.通过类名访问
    Person2::func();
}



int main()
{
    test01();
    //test02();
    //test03();

    return 0;
}