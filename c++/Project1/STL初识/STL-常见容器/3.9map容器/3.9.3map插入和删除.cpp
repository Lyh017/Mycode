#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int>&m)
{
    for(auto i : m)
    {
        cout<<"key="<<i.first<<" value="<<i.second<<endl;
    }
    cout<<endl;
}    

//map插入和删除
void test01()
{
    map<int,int>m;
    //插入
    //第一种
    m.insert(pair<int,int>(1,10));

    //第二种
    m.insert(make_pair(2,20));

    //第三种
    m.insert(map<int,int>::value_type(3,30));

    //第四种
    m[4]=40;
    //[]不建议插入，但是可以用来查找，利用key访问value
    cout<<m[4]<<endl;

    printMap(m);

    //删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);   //按照key删除
    printMap(m);

    //m.erase(m.begin(),m.end()); 清空
    m.clear();
    printMap(m);
}



int main()
{
    test01();
    return 0;
}