#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

//�ڽ��������� �߼��º���
//�߼��� logical_not
void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //�߼���  ������v���˵�v2�У���ִ��ȡ������
    vector<int>v2;
    v2.resize(v.size());  //ָ������
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>()); //ԭ������ʼ��������ԭ����������������Ŀ��������ʼ���������º���(�ڰ����ڼ����ȡ������)
    for(auto i : v2)
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