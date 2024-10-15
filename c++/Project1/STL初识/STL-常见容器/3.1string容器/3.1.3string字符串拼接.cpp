#include<iostream>
using namespace std;
#include<string>

//string字符串拼接
//string内部重载了+=

void test01()
{
    string str1="我";
    str1+="爱玩游戏";
    cout<<"str1="<<str1<<endl;

    str1+=":";   //追加一个字符
    cout<<"str1="<<str1<<endl;

    string str2="LOL APEX";
    str1+=str2;
    cout<<"str1="<<str1<<endl;


    string str3="I";
    str3.append(" love ");
    cout<<"str3="<<str3<<endl;

    str3.append("game abcd",4);  //把字符串前n个字符连接到当前字符串结尾
    cout<<"str3="<<str3<<endl;

    //str3.append(str2);
    cout<<"str3="<<str3<<endl;

    str3.append(str2,4,4);  //string& append(const string &s,int pos,int n),字符串s中从pos开始的n个字符连接到字符串结尾
    cout<<"str3="<<str3<<endl;
}

int main()
{
    test01();
    return 0;
}