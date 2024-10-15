#include<iostream>
using namespace std;



//������������� ++

//�Զ�������
class MyInteger
{
    friend ostream & operator<<(ostream& out,MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    //����ǰ��++�����

    MyInteger& operator++()  //����&��Ϊ��һֱ��һ�����ݽ��е�������
    {
        m_Num++;
        return *this;
    }

    //���غ���++�����
    MyInteger operator++(int)  //int��һ��ռλ������������������ǰ�úͺ��õ���,���ﷵ�ص�ֵ����Ϊtemp��һ���ֲ���������ǰ����ִ����ͱ�����
    {   
        //�� ��¼��ʱ���
        MyInteger temp = *this;
        //�����
        m_Num++;
        //��󽫼�¼�������
        return temp;
    }


private:

    int m_Num;


};

ostream & operator<<(ostream& out,MyInteger myint)
{
    cout<<"myint = "<<myint.m_Num;
    return out;
}


void test01()
{
    MyInteger myint;
    cout<<++myint<<endl;
}


void test02()
{
    MyInteger myint;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}

int main()
{
    test01();
    test02();
    return 0;
}