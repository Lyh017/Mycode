#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//���ñ����㷨transform

//�º���  ����������ʵ�ְ��˹����е�һЩ���� Ҳ����ֱ�ӷ���
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

    vector<int>vTarget;  //Ŀ������ ��Ҫ��ǰ���ٿռ�
    vTarget.resize(v.size());
    //��ԭ���������ᵽĿ������
    transform(v.begin(),v.end(),vTarget.begin(),Transform());

    for_each(vTarget.begin(),vTarget.end(),Print());
    cout<<endl;
}

int main()
{
    test01();
    return 0;
}