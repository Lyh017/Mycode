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
//set������С�ͽ���
void test01()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(5);
    s1.insert(19);
    s1.insert(38);

    printSet(s1);

    //�ж��Ƿ�Ϊ��
    if(s1.empty())
    {
        cout<<"Ϊ��"<<endl;
    }
    else{
        cout<<"��Ϊ��"<<endl;
        cout<<"s1�Ĵ�СΪ:"<<s1.size()<<endl;
    }

}

//����
void test02()
{
    set<int>s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    s2.insert(500);

    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(5);
    s1.insert(19);
    s1.insert(38);

    cout<<"����ǰ��"<<endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);
    cout<<"������"<<endl;
    printSet(s1);
    printSet(s2);
}

int main()
{
    test02();
    return 0;
}