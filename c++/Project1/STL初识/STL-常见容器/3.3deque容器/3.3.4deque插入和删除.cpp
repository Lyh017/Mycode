#include<iostream>
using namespace std;
#include<deque>

//deque��������ɾ��

void printDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//���˲���
void test01()
{
    deque<int>d1;

    //β��
    d1.push_back(10);
    d1.push_back(20);

    //ͷ��
    d1.push_front(100);
    d1.push_front(200);

    //βɾ
    d1.pop_back();
    //ͷɾ
    d1.pop_front();

    printDeque(d1);

}

void test02()
{
    deque<int>d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_front(100);
    d2.push_front(300);

    printDeque(d2);

    //insert����
    d2.insert(d2.begin(),1000);
    printDeque(d2);

    d2.insert(d2.begin(),3,2000);  //��3��2000
    printDeque(d2);

    //����������в���
    deque<int>d3;
    d3.push_back(1);
    d3.push_back(2);
    d3.push_back(3);

    d2.insert(d2.begin(),d3.begin(),d3.end()); //��posλ�ò�����������

    printDeque(d2);
}

void test03()
{
    deque<int>d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_front(100);
    d2.push_front(300);

    //ɾ��
    deque<int>::iterator it=d2.begin();
    it++;
    d2.erase(it);
    printDeque(d2);

    //������ɾ��
    d2.erase(d2.begin(),d2.end());  //d2.clear()
    printDeque(d2);
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}