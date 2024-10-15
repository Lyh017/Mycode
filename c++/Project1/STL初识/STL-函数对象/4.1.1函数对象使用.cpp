#include<iostream>
using namespace std;

//函数对象(仿函数)
//函数对象在使用时可以像普通函数那样调用，可以有参数，可以有返回值
//函数对象超出普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递

class MyAdd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};

void test01()
{
    MyAdd add;  //函数对象
    int ret=add(1,2);
    cout<<"ret="<<ret<<endl;
}

class Myprint
{
public:

    Myprint()
    {
        this->count=0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        count++;
    }

    int count;
};

void test02()
{
    Myprint print;
    print("Hello");
    print("Hello");
    print("Hello");
    print("Hello");
    cout<<"Myprint调用了"<<print.count<<"次"<<endl;
}

void doPrint(Myprint& p,string st)
{
    p(st);
}
void test03()
{
    Myprint print;
    doPrint(print,"How to be a ML expert?");

}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}