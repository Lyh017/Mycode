#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//成员属性设置私有
//1.可以自己控制读写权限  2.对于写可以检测数据有效性

class Person
{
public:
	//公有方法对私有属性控制
	void SetName(string name)
	{
		m_Name = name;
	}
	string GetName()
	{
		return m_Name;
	}
	int getAge()
	{
		return m_Age;
	}
	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "年龄输入有误，赋值失败" << endl;
			return;
		}
		else
		{
			m_Age = age;
		}
		
	}
private:
	string m_Name; //姓名，可读可写
	int m_Age = 18; //年龄，只读  也可以写（必须在0到150之间）
	string m_Idol; //偶像，只写
};


int main()
{
	Person p;
	p.SetName("Zhangsan");
	p.setAge(16);
	cout << "姓名: " << p.GetName() << endl;
	cout << "年龄：" << p.getAge() << endl; //获取年龄

	return 0;
}