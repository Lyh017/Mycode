#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

//deque»›∆˜≈≈–Ú

void printDeque(deque<int>& d)
{
    for(deque<int>::iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    printDeque(d);

    //≈≈–Ú
    sort(d.begin(),d.end());
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}