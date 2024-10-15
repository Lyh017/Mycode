#include<iostream>
using namespace std;


//函数模板注意事项
//1.自动类型推导，必须推导出一致的数据类型T才可以使用
//2.模板必须要确定出T的数据类型才可以使用

template<typename T>  //typename可以替换成class
void mySwap(T& a,T& b)
{
    
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a=10;
    int b=20;
    //char c='c';
    //mySwap(a,c);  错误！推导不出一致的T类型
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}
template<typename T>
void func()
{
    cout<<"func函数的调用"<<endl;
}

void test02()
{
    func<int>();  //虽然函数里没有使用T,但是必须要给T一个类型才可以使用该模板
}

int main()
{
    test01();
    return 0;
}