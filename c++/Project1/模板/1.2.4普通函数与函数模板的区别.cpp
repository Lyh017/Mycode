#include<iostream>
using namespace std;

//��ͨ�����뺯��ģ������
//1.��ͨ�������ÿ��Է�����ʽ����ת��
//2.����ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��


//��ͨ����
int Add(int a,int b)
{
    return a+b;
}

//����ģ��
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
    //�Զ������Ƶ� ���ᷢ����ʽ����ת��
    //cout<<myAdd(a,c)<<endl;

    //��ʾָ������
    myAdd<int>(a,c);
    cout<<myAdd<int>(a,c)<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}