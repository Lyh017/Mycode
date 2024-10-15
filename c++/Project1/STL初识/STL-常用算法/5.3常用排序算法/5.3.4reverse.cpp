#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//将容器内元素进行反转
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<"反转前:"<<endl;
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    reverse(v.begin(),v.end());
    cout<<"反转后:"<<endl;
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