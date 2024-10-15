#include<iostream>
using namespace std;


//����ģ��

//�����������͵ĺ���
void swapint(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


//��������������
void swapdouble(double &a,double &b)
{
    double temp=a;
    a=b;
    b=temp;
}

//����ģ��
template<typename T>  //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//ģ���Ŀ����Ϊ����߸����ԣ������Ͳ�����

void test01()
{
    int a=10;
    int b=20;
    //swapint(a,b);
    //���ú���ģ��������
    //���ַ���ʹ��
    //1.�Զ������Ƶ�
    //mySwap(a,b);

    //2.��ʾָ������
    //mySwap<int>(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    double c=11.1;
    double d=19.9;
    swapdouble(c,d);
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
}

int main()
{
    test01();
    return 0;
}
