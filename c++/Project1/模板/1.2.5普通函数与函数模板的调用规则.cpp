#include<iostream>
using namespace std;

//��ͨ�����뺯��ģ����ù���
//1.�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//3.����ģ����Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

// void myPrint(int a,int b)
// {
//     cout<<"���õ���ͨ����"<<endl;
// }

template<typename T>
void myPrint(T a,T b)
{
    cout<<"���õ�ģ��"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}

template<typename T>
void myPrint(T a,T b,T c)
{
    cout<<"���õ�����ģ��"<<endl;
}

void test01()
{
    // int a=10;
    // int b=20;
    // int c=1;
    //myPrint(a,b);

    //ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
    //myPrint<>(a,b);
    //myPrint(a,b,c);

    //�������ģ��������õ�ƥ�䣬���ȵ��ú���ģ�塢
    char c1='a';
    char c2='n';
    myPrint(c1,c2); //�������ú���ģ��
}

int main()
{
    test01();
    return 0;
}