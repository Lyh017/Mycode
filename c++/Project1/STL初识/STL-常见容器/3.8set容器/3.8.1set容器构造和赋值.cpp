#include<iostream>
using namespace std;
#include<set>

void printSet(set<int>& s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set容器构造和赋值
void test01()
{
    set<int>s1;
    s1.insert(10);    //插入数据只有insert方式
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    printSet(s1);
    //set容器特点：所有元素插入的时候会自动被排序
    //set容器不允许插入重复值

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);

    //赋值
    set<int>s3=s2;
    printSet(s3);
}

int main()
{
    test01();
    return 0;
}
