#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//adjacent ���������ظ�Ԫ�� �ҵ��˷�������Ԫ�صĵ�һ��λ�õĵ�����

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
    cout<<"�ҵ������ظ�Ԫ��"<<*it<<endl;
}

int main()
{
    test01();
    return 0;
}