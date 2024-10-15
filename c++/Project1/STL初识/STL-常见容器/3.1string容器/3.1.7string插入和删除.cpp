#include<iostream>
using namespace std;
#include<string>

//字符串插入和删除
void test01()
{
    string str="hello";

    //插入
    str.insert(1,"111");
    cout<<str<<endl;

    //删除
    str.erase(1,3);  //从哪个位置起，删多少个
    cout<<str<<endl;
}


int main()
{
    test01();
    return 0;
}