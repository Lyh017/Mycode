#include<iostream>
using namespace std;
#include<set>

//set������multiset��������
void test01()
{
    set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    pair<set<int>::iterator,bool> ret=s.insert(10);
    if(ret.second)
    {
        cout<<"����ɹ�"<<endl;
    }
    else{
        cout<<"����ʧ��"<<endl;
    }

    multiset<int>ms;
    //��������ظ�ֵ
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);

    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

int main()
{
    test01();
    return 0;
}