#include<iostream>
#include<string>
using namespace std;

//��ģ����̳�

template<class T>
class Base
{
public:
    T m;
};

class Son : public Base<int>   //����Ҫ֪�������е�T�����ͣ����ܼ̳и�����
{

};

void test01()
{
    //Son s1;
}

//��������ָ��������T�����ͣ�����Ҳ��Ҫ�����ģ��
template<class T1,class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout<<"T2��������:"<<typeid(T2).name()<<endl;
        cout<<"T1��������:"<<typeid(T1).name()<<endl;
    }
    T1 obj;
};

void test02()
{
    Son2<int,char> s2;
}


//


int main()
{
    
    test02();
    return 0;
}

//�ܽᣬ�����������ģ�壬������Ҫָ����������T����������