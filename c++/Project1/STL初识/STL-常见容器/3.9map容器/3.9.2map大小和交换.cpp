#include<iostream>
using namespace std;
#include<map>

//map大小和交换

void printMap(map<int,int>&m)
{
    for(auto i : m)
    {
        cout<<"key="<<i.first<<" value="<<i.second<<endl;
    }
    cout<<endl;
}

//大小
void test01()
{
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    if(m1.empty())
    {
        cout<<"为空"<<endl;
    }
    else{
        cout<<"不为空"<<endl;
        cout<<"大小是:"<<m1.size()<<endl;
    }

}

//交换
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
    cout<<"交换前:"<<endl;
    printMap(m1);
    printMap(m2);

    m1.swap(m2);
    cout<<"交换后"<<endl;
    printMap(m1);
    printMap(m2);

}

int main()
{
    //test01();
    test02();
    return 0;
}