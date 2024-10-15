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
//list�����ɾ��
void test01()
{
    list<int>L;
    //β��
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    
    L.push_front(10);
    L.push_front(20);
    L.push_front(30);
    printList(L);

    //βɾ
    L.pop_back();
    //ͷɾ
    L.pop_front();
    printList(L);

    //insert����
    list<int>::iterator it=L.begin();
    L.insert(++it,999);    //�ṩ������
    printList(L);

    //ɾ��
    it=L.begin();
    L.erase(++it);    //list��������֧����Ծʽ���ʣ�ֻ��ǰ�ƺͺ���
    printList(L);

    //�Ƴ�
    L.push_back(120);
    L.push_back(120);
    L.push_back(120);
    printList(L);
    L.remove(120);  //ɾ������120
    printList(L);

    //���
    L.clear();
    printList(L);
}

int main()
{
    test01();
    return 0;
}