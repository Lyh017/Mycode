#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//常用遍历算法 for-each

//普通函数
void print01(int val)
{
    cout<<val<<" ";

}

//仿函数
class Print
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};

void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);  //普通函数传函数名
    cout<<endl;

    for_each(v.begin(),v.end(),Print());  //仿函数传函数对象，这里是一个匿名函数
    cout<<endl;
}

int main()
{
    test01();
    return 0;
}