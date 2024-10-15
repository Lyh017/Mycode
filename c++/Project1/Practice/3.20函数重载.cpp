#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//函数重载，可以让函数名相同，提高复用性
//函数重载满足条件
//1.同一个作用域下 2.函数名称相同 3.函数的参数类型不同，或者个数不同，或者顺序不同
//注意:函数的返回值不可以作为函数重载的条件

void func()
{
	cout << "func的调用" << endl;
}

void func(int a)
{
	cout << "func的调用!" << endl;
}

void func(double a)
{
	cout << "func的调用!!!" << endl;
}

//函数重载的注意事项
//1.引用作为重载的条件

void fun(int& a)
{
	cout << "fun(int& a)的调用" << endl;
}

void fun(const int& a)
{
	cout << "fun(const int& a)的调用" << endl;
}

//2.函数重载碰到默认参数

void func2(int a,int b = 10)
{
	cout << "func2(int a,int b)的调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a)的调用" << endl;
}

int main()
{
	
	//func(10.1);
	
	int a = 10;  //int &a = 10;不合法
	//fun(a);
	//fun(10); 
	//func2(10);   两个func2都能调用

	return 0;
}