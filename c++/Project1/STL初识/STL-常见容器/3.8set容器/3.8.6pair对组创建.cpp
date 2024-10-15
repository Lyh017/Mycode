#include<iostream>
using namespace std;
#include<string>

//pair对组的创建

void test01()
{
    //第一种方式
    pair<string,int> p("Tom",20);
    cout<<p.first<<p.second<<endl;

    //第二种方式
    pair<string,int>p2= make_pair("Ken",30);
    cout<<p2.first<<p2.second<<endl;

    pair<string,int>p3={"Mike",10};
    cout<<p3.first<<p3.second<<endl;
}

int main()
{
    test01();
    return 0;
}