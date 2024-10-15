#include<iostream>
using namespace std;


//函数模板

//交换两个整型的函数
void swapint(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


//交换两个浮点型
void swapdouble(double &a,double &b)
{
    double temp=a;
    a=b;
    b=temp;
}

//函数模板
template<typename T>  //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//模板的目的是为了提高复用性，将类型参数化

void test01()
{
    int a=10;
    int b=20;
    //swapint(a,b);
    //利用函数模板来交换
    //两种方法使用
    //1.自动类型推导
    //mySwap(a,b);

    //2.显示指定类型
    //mySwap<int>(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    double c=11.1;
    double d=19.9;
    swapdouble(c,d);
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
}

int main()
{
    test01();
    return 0;
}
