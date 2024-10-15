#include<iostream>
using namespace std;
#include<map>

//map查找和统计
//find(key)  查找key是否存在，返回该键元素的迭代器，若不存在返回end迭代器
//count(key)  统计key的元素个数
void test01()
{
    map<int,int>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));

    //查找
    auto pos=m.find(4);
    if(pos!=m.end())
    {
        cout<<"找到了元素:"<<pos->second<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }

    //统计
    int num=m.count(3);
    cout<<"num="<<num<<endl;  //对于map容器，不允许插入重复key元素，对于count统计而言，结果要不是1，要不是0，multimap可能大于1
}

int main()
{
    test01();
    return 0;
}