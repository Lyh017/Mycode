#include<iostream>
using namespace std;
#include<functional> //�ڽ���������ͷ�ļ�
//�ڽ��������� �����º���

//negateһԪ�º���  ȡ���º���
void test01()
{
    negate<int> n;    //�ڽ��ĺ�������

    cout<<n(50)<<endl;
}
//plus ��Ԫ�º��� �ӷ�
void test02()
{
    plus<int> p;
    //minus<int>p;
    //multiplies<int>p;
    //divides<int>p;
    //modulus<int>p;  ȡģ
    cout<<p(10,20)<<endl;
}

int main()
{
    test01();
    test02();
    return 0;
}