#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//adjacent 查找相邻重复元素 找到了返回相邻元素的第一个位置的迭代器

void test01()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);

    vector<int>::iterator it=adjacent_find(v.begin(),v.end());
    cout<<"找到相邻重复元素"<<*it<<endl;
}

int main()
{
    test01();
    return 0;
}