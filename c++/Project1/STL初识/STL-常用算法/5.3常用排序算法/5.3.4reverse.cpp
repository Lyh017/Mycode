#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//��������Ԫ�ؽ��з�ת
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<"��תǰ:"<<endl;
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    reverse(v.begin(),v.end());
    cout<<"��ת��:"<<endl;
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