#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>

//ϴ�� ָ����Χ�ڵ�Ԫ�������������
void test01()
{
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //random_shuffle����˳��
    //random_shuffle(v.begin(),v.end());
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