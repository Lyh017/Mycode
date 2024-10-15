#include<iostream>
using namespace std;
#include<string>

//字符串查找和替换

//1.查找
void test01()
{
    string str1 ="abcdefgde";
    int pos = str1.find("de");
    if(pos==-1)
    {
        cout<<"未找到字符串"<<endl;
    }
    else
    {
        cout<<"找到字符串,pos="<<pos<<endl;
    }
    
    //rfind 和find区别
    //rfind从右往左查找，find从左往右查找
    int pos1=str1.rfind("de");
    cout<<"pos1="<<pos1<<endl;

}

//2.替换
void test02()
{
    string str1="abcdefg";
    str1.replace(1,3,"1111");  //string& replace(int pos,int n,const string& str ),可以是string也可以是char* ，替换从pos开始的n个字符
    cout<<str1<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}