#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//���������㷨sort
void test01()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(3);
    v.push_back(9);
    //����sort���� Ĭ������
    sort(v.begin(),v.end());
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //�ı�Ϊ����
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