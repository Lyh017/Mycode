#include<iostream>
using namespace std;
#include<string>

//pair����Ĵ���

void test01()
{
    //��һ�ַ�ʽ
    pair<string,int> p("Tom",20);
    cout<<p.first<<p.second<<endl;

    //�ڶ��ַ�ʽ
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