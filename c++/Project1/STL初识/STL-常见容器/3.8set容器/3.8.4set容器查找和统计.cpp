#include<iostream>
using namespace std;
#include<set>

//set查找和统计
void test01()
{
    set<int>s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);

    set<int>::iterator pos=s1.find(4);  //查找key是否存在，返回该键的元素的迭代器，若不存在返回set.end();
    if(pos!=s1.end())
    {
        cout<<"找到了元素:"<<*pos<<endl;
    }
    else{
        cout<<"未找到元素"<<endl;
    }
}
//统计
void test02()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    int num=s1.count(40); //统计40的个数
    cout<<"num="<<num<<endl;
    //对于set而言，统计结果要么是0，要么是1
}

int main()
{
    //test01();
    test02();
    return 0;
}