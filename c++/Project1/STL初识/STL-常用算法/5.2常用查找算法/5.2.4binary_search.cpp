#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//二分查找，找到返回true 否则false
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    bool ret=binary_search(v.begin(),v.end(),9);
    if(ret)
    {
        cout<<"找到了"<<endl;
    }
}

int main()
{
    test01();
    return 0;
}