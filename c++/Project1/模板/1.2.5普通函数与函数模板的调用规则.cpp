#include<iostream>
using namespace std;

//普通函数与函数模板调用规则
//1.如果函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

// void myPrint(int a,int b)
// {
//     cout<<"调用的普通函数"<<endl;
// }

template<typename T>
void myPrint(T a,T b)
{
    cout<<"调用的模板"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}

template<typename T>
void myPrint(T a,T b,T c)
{
    cout<<"调用的重载模板"<<endl;
}

void test01()
{
    // int a=10;
    // int b=20;
    // int c=1;
    //myPrint(a,b);

    //通过空模板参数列表 强制调用 函数模板
    //myPrint<>(a,b);
    //myPrint(a,b,c);

    //如果函数模板产生更好的匹配，优先调用函数模板、
    char c1='a';
    char c2='n';
    myPrint(c1,c2); //这里会调用函数模板
}

int main()
{
    test01();
    return 0;
}