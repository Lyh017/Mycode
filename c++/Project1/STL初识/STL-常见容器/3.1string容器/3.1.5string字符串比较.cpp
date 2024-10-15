#include<iostream>
using namespace std;
#include<string>


//字符串之间的比较
//字符串比较是按字符的ASCII码进行对比
// = 返回0 ，> 返回 1 ，< 返回 -1

void test01()
{
    string str1="xello";
    string str2="yello";
    if(str1.compare(str2)==0)
    {
        cout<<"str1等于str2"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<<"str1大于str2"<<endl;
    }
    else{
        cout<<"str1小于str2"<<endl;
    }
}

int main()
{
    test01();
    return 0;

}