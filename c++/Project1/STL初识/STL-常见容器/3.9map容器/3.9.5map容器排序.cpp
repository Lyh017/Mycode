#include<iostream>
using namespace std;
#include<map>

class compare
{
public:
    bool operator()(int a,int b)
    {
        //����
        return a>b;
    }
};

//map��������
void test01()
{
    map<int,int>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(6,60));
    m.insert(make_pair(4,40));
    m.insert(make_pair(5,50));

    for(auto i : m)
    {
        cout<<"key="<<i.first<<" value="<<i.second<<endl;
    }
    cout<<endl;

    //�ı�����������ģ�����
    map<int,int,compare>m1;
    m1.insert(make_pair(1,10));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,30));
    m1.insert(make_pair(6,60));
    m1.insert(make_pair(4,40));
    m1.insert(make_pair(5,50));

    for(auto i : m1)
    {
        cout<<"key="<<i.first<<" value="<<i.second<<endl;
    }
    cout<<endl;
    

}

int main()
{
    test01();
    return 0;
}