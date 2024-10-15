#include<iostream>
using namespace std;
#include<functional> //内建函数对象头文件
//内建函数对象 算术仿函数

//negate一元仿函数  取反仿函数
void test01()
{
    negate<int> n;    //内建的函数对象

    cout<<n(50)<<endl;
}
//plus 二元仿函数 加法
void test02()
{
    plus<int> p;
    //minus<int>p;
    //multiplies<int>p;
    //divides<int>p;
    //modulus<int>p;  取模
    cout<<p(10,20)<<endl;
}

int main()
{
    test01();
    test02();
    return 0;
}