#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void printList(const list<int>& L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list容器反转和排序
void test01()
{
    //反转
    list<int>L1;

    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    //反转
    L1.reverse();
    cout<<"反转后:"<<endl;
    printList(L1);
}

bool myCompare(int v1,int v2)
{
    //降序 就让第一个数大于第二个数
    return v1 > v2;
}
//排序
void test02()
{
    list<int>L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(30);
    L1.push_back(40);

    cout<<"排序后:"<<endl;

    //所有不支持随机访问迭代器的容器，不可以使用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应的一些算法
    //sort(L1.begin(),L1.end());
    //L1.sort();  //调用成员函数，默认排序规则是从小到大
    L1.sort(myCompare);  //降序
    printList(L1);
}

int main()
{
    test02();
    return 0;
}