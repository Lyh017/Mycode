#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//merge
void test01()
{
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);

    }
    vector<int>vtarget; //目标容器  需要提前开辟空间
    vtarget.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarget.begin()); //需要两个有序序列
    for(auto i : vtarget)
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