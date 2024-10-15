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

//map�����ɾ��
void test01()
{
    map<int,int>m;
    //����
    //��һ��
    m.insert(pair<int,int>(1,10));

    //�ڶ���
    m.insert(make_pair(2,20));

    //������
    m.insert(map<int,int>::value_type(3,30));

    //������
    m[4]=40;
    //[]��������룬���ǿ����������ң�����key����value
    cout<<m[4]<<endl;

    printMap(m);

    //ɾ��
    m.erase(m.begin());
    printMap(m);

    m.erase(3);   //����keyɾ��
    printMap(m);

    //m.erase(m.begin(),m.end()); ���
    m.clear();
    printMap(m);
}



int main()
{
    test01();
    return 0;
}