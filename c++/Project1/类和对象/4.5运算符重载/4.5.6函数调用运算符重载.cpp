#include<iostream>
#include<string>
using namespace std;

//函数调用运算符重载

//打印输出类
class MyPrint
{
public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout<<test<<endl;
    }

};


void test01()
{
    MyPrint myprint;
    myprint("hello world");  //由于使用起来非常类似于函数调用，因此被称为仿函数
    myprint.operator()("Jerry");

}

//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};


void test02()
{
    MyAdd add;
    int ret = add(3,4);
    int ret = add.operator()(3,4);
    cout << ret << endl;

    //匿名函数对象
    cout << MyAdd()(100,100) << endl;

}


int main()
{

    test01();
    test02();
    return 0;
}