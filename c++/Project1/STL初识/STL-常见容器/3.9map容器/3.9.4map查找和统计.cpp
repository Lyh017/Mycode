#include<iostream>
using namespace std;
#include<map>

//map���Һ�ͳ��
//find(key)  ����key�Ƿ���ڣ����ظü�Ԫ�صĵ��������������ڷ���end������
//count(key)  ͳ��key��Ԫ�ظ���
void test01()
{
    map<int,int>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));

    //����
    auto pos=m.find(4);
    if(pos!=m.end())
    {
        cout<<"�ҵ���Ԫ��:"<<pos->second<<endl;
    }
    else
    {
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }

    //ͳ��
    int num=m.count(3);
    cout<<"num="<<num<<endl;  //����map����������������ظ�keyԪ�أ�����countͳ�ƶ��ԣ����Ҫ����1��Ҫ����0��multimap���ܴ���1
}

int main()
{
    test01();
    return 0;
}