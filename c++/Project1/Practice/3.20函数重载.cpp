#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//�������أ������ú�������ͬ����߸�����
//����������������
//1.ͬһ���������� 2.����������ͬ 3.�����Ĳ������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
//ע��:�����ķ���ֵ��������Ϊ�������ص�����

void func()
{
	cout << "func�ĵ���" << endl;
}

void func(int a)
{
	cout << "func�ĵ���!" << endl;
}

void func(double a)
{
	cout << "func�ĵ���!!!" << endl;
}

//�������ص�ע������
//1.������Ϊ���ص�����

void fun(int& a)
{
	cout << "fun(int& a)�ĵ���" << endl;
}

void fun(const int& a)
{
	cout << "fun(const int& a)�ĵ���" << endl;
}

//2.������������Ĭ�ϲ���

void func2(int a,int b = 10)
{
	cout << "func2(int a,int b)�ĵ���" << endl;
}

void func2(int a)
{
	cout << "func2(int a)�ĵ���" << endl;
}

int main()
{
	
	//func(10.1);
	
	int a = 10;  //int &a = 10;���Ϸ�
	//fun(a);
	//fun(10); 
	//func2(10);   ����func2���ܵ���

	return 0;
}