#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//��Ԫν��

class Compare
{
public: 
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(),v.end());
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //ʹ�ú������� �ı��㷨���ԣ��ı����Ϊ�Ӵ�С
    sort(v.begin(),v.end(),Compare());
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