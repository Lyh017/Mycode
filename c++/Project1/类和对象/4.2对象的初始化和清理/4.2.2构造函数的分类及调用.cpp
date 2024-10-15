#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1.构造函数的分类及调用
//分类
//按照参数分类 无参构造(默认构造)和有参构造
//按照类型分类 普通构造  拷贝构造
class Person
{
public:
	Person()
	{
		cout << "Person的无参构造函数的调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数的调用" << endl;
	}
	
	//拷贝构造函数
	Person(const Person &p)
	{
		age = p.age;   //将传入的人身上的所有属性，拷贝到我身上
		cout << "Person的拷贝构造函数的调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数的调用" << endl;
	}
	int age;
};

//调用
void test01()
{
	//1.括号法
	//Person p1;  //默认构造函数调用

	//Person p2(10);   //有参构造函数

	//Person p3(p2);   //拷贝构造函数

	//注意事项1
	//调用默认构造函数的时候不要加（）,编译器会认为这是一个函数的声明，不会认为在创建对象


	
	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p3.age << endl;

	//2.显示法

	Person p1;
	Person p2 = Person(10);  //有参构造 Person(10）是一个匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
	Person p3 = Person(p2);  //拷贝构造

	//注意事项2
	//不要利用拷贝构造函数 初始化匿名对象,编译器会认为Person(p3) == Person p3;
	//Person(p3);
	

	//3.隐式转换法
	Person p4 = 10;  //相当于写了Person p4 = Person(10)
	Person p5 = p4;
}

int main()
{
	test01();
	return 0;
}