#include<iostream>
using namespace std;
#include<string>

//string�ı�����һ���࣬���ڲ���װ��char*

//string�Ĺ��캯��


void test01()
{
    string s1;   //Ĭ�Ϲ���

    const char* str="hello world";
    string s2(str);

    cout<<"s2="<<s2<<endl;

    string s3(s2);
    cout<<"s3="<<s3<<endl;
 
    //ʹ��n���ַ�c��ʼ��
    string s4(10,'a');
    cout<<"s4="<<s4<<endl;
}

int main()
{
    test01();
    return 0;
}