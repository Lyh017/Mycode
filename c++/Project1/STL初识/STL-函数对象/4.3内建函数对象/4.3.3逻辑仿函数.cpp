#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

//内建函数对象 逻辑仿函数
//逻辑非 logical_not
void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //逻辑非  将容器v搬运到v2中，并执行取反操作
    vector<int>v2;
    v2.resize(v.size());  //指定容量
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>()); //原容器起始迭代器，原容器结束迭代器，目标容器起始迭代器，仿函数(在搬运期间完成取反操作)
    for(auto i : v2)
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