#include<iostream>
#include<list>

using namespace std;

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(11);
    L1.push_back(12);
    L1.push_back(13);

    //L1[0] ��������[]����list�����е�Ԫ��
    //L1.at(0)  ��������at��ʽ����
    //ԭ����list�����������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�

    cout<<"��һ��Ԫ��Ϊ:"<<L1.front()<<endl;
    cout<<"���һ��Ԫ��Ϊ:"<<L1.back()<<endl;

    //��֤�������ǲ�֧��������ʵ�
    list<int>::iterator it=L1.begin();
    it++;
    it--;  //֧��˫��
    //it=it+1 ��֧��������� 
}

int main()
{
    test01();
    return 0;
}