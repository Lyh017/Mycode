#include<iostream>
using namespace std;
#include<string>

//string求字串

void test01()
{
    string str="abcdef";
    string sub=str.substr(1,3);
    cout<<"sub="<<sub<<endl;

}

//实用操作
void test02()
{
    string email="zhangsan@sina.com";

    //从邮件地址获取用户名

   int pos=email.find('@');
   string name=email.substr(0,pos); //第一个是从哪个位置起，第二个是截多少个字符，不是下标
   cout<<name<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}