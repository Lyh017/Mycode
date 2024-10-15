#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
//内建的函数对象  关系仿函数
//大于 greater

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //降序
    //greater<int>() 内建函数匿名对象
    sort(v.begin(),v.end(),greater<int>());
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    test01();
    return 0;
}