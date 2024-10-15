#include<iostream>
#include<list>

using namespace std;

void printList(const list<int>& L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list插入和删除
void test01()
{
    list<int>L;
    //尾插
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    
    L.push_front(10);
    L.push_front(20);
    L.push_front(30);
    printList(L);

    //尾删
    L.pop_back();
    //头删
    L.pop_front();
    printList(L);

    //insert插入
    list<int>::iterator it=L.begin();
    L.insert(++it,999);    //提供迭代器
    printList(L);

    //删除
    it=L.begin();
    L.erase(++it);    //list迭代器不支持跳跃式访问，只能前移和后移
    printList(L);

    //移除
    L.push_back(120);
    L.push_back(120);
    L.push_back(120);
    printList(L);
    L.remove(120);  //删除所有120
    printList(L);

    //清空
    L.clear();
    printList(L);
}

int main()
{
    test01();
    return 0;
}