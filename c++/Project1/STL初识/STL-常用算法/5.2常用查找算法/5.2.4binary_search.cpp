#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//���ֲ��ң��ҵ�����true ����false
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
        cout<<"�ҵ���"<<endl;
    }
}

int main()
{
    test01();
    return 0;
}