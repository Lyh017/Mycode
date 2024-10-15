#include<iostream>
using namespace std;
#include<map>

//map��С�ͽ���

void printMap(map<int,int>&m)
{
    for(auto i : m)
    {
        cout<<"key="<<i.first<<" value="<<i.second<<endl;
    }
    cout<<endl;
}

//��С
void test01()
{
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    if(m1.empty())
    {
        cout<<"Ϊ��"<<endl;
    }
    else{
        cout<<"��Ϊ��"<<endl;
        cout<<"��С��:"<<m1.size()<<endl;
    }

}

//����
void test02()
{
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    map<int,int>m2;
    m2.insert(pair<int,int>(1,100));
    m2.insert(pair<int,int>(2,200));
    m2.insert(pair<int,int>(3,300));
    m2.insert(pair<int,int>(4,400));
    cout<<"����ǰ:"<<endl;
    printMap(m1);
    printMap(m2);

    m1.swap(m2);
    cout<<"������"<<endl;
    printMap(m1);
    printMap(m2);

}

int main()
{
    //test01();
    test02();
    return 0;
}