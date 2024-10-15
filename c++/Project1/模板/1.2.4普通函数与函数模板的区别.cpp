#include<iostream>
using namespace std;

//普通函数与函数模板区别
//1.普通函数调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型，可以发生隐式类型转换


//普通函数
int Add(int a,int b)
{
    return a+b;
}

//函数模板
template<typename T>
T myAdd(T a,T b)
{
    return a + b;
}

void test01()
{
    int a=10;
    //int b=20;
    char c='c'; //c - 99

    cout<<Add(a,c)<<endl;
}

void test02()
{
    int a=10;
    //int b=20;
    char c='c';
    //自动类型推导 不会发生隐式类型转换
    //cout<<myAdd(a,c)<<endl;

    //显示指定类型
    myAdd<int>(a,c);
    cout<<myAdd<int>(a,c)<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}