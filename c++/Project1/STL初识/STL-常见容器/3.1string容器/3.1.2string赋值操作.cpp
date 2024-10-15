#include<iostream>
using namespace std;
#include<string>

// string& operator=(const char* s);    //char*类型的字符串 赋值给当前的字符串
// string& operator=(const string &s);  //把字符串s赋给当前字符串
// string& operator=(char c);         //字符赋给当前字符串
// string& assgin(const char* s);      //把字符串s赋给当前字符串
// string& assgin(const string &s);    //把字符串s赋给当前字符串
// string& assgin(const char* s,int n);  //把字符串s的前n个赋给当前字符串
// string& assgin(int n,char c);        //用n个字符c赋给当前字符串


void test01()
{
    string str1;
    str1="hello world";
    cout<<"str1="<<str1<<endl;

    string str2;
    str2=str1;
    cout<<"str2="<<str2<<endl;

    string str3;
    str3='a';

    string str4;
    str4.assign("hello,c++");
    cout<<"str4="<<str4<<endl;

    string str5;
    str5.assign("hello,c++",5);
    cout<<"str5="<<str5<<endl;
    
    string str6;
    str6.assign(str5);

    string str7;
    str7.assign(10,'w');
    cout<<"str7="<<str7<<endl;
}

int main()
{
    test01();
    return 0;
}