#include<iostream>
using namespace std;
#include<deque>

//deque数据存取

void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //通过[]访问元素
    for(int i=0;i<6;i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    //at方式访问元素
    for(int i=0;i<6;i++)
    {
        cout<<d.at(i)<<" ";
    }
    cout<<endl;

    cout<<"第一个元素为:"<<d.front()<<endl;
    cout<<"最后一个元素为:"<<d.back()<<endl;
}

int main()
{
    test01();
    return 0;
}