#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
//�ڽ��ĺ�������  ��ϵ�º���
//���� greater

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

    //����
    //greater<int>() �ڽ�������������
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