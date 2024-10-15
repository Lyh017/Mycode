#include<iostream>
using namespace std;
#include<vector>

//vector数据结构与数组非常相似，也称单端数组
//vector可以动态扩展，不是在原空间之后续接新空间，而是寻找更大的内存空间，然后将原数据拷贝新空间，释放原空间
//vector容器的迭代器是支持随机访问的迭代器

//vector构造函数

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    vector<int> v1;  //默认构造，无参构造
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);

    }
    printVector(v1);

    //通过区间的方式进行构造
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

    //n个elem方式构造
    vector<int>v3(10,1);   //10个1
    printVector(v3);

    //拷贝构造
    vector<int>v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}