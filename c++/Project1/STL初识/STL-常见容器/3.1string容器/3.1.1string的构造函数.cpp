#include<iostream>
using namespace std;
#include<string>

//string的本质是一个类，类内部封装了char*

//string的构造函数


void test01()
{
    string s1;   //默认构造

    const char* str="hello world";
    string s2(str);

    cout<<"s2="<<s2<<endl;

    string s3(s2);
    cout<<"s3="<<s3<<endl;
 
    //使用n个字符c初始化
    string s4(10,'a');
    cout<<"s4="<<s4<<endl;
}

int main()
{
    test01();
    return 0;
}