#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//常用遍历算法transform

//仿函数  可以在这里实现搬运过程中的一些运算 也可以直接返回
class Transform
{
public:
    int operator()(int val)
    {
        //return val; 
        return val+100;
    }
};

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

    vector<int>vTarget;  //目标容器 需要提前开辟空间
    vTarget.resize(v.size());
    //把原容器的数搬到目标容器
    transform(v.begin(),v.end(),vTarget.begin(),Transform());

    for_each(vTarget.begin(),vTarget.end(),Print());
    cout<<endl;
}

int main()
{
    test01();
    return 0;
}