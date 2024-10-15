#include<iostream>
using namespace std;


//µİ¼õÔËËã·ûÖØÔØ
class MyInteger
{
    friend ostream & operator<<(ostream& out,MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    MyInteger& operator--()
    {
        --m_Num;
        return *this;
    }

    MyInteger operator--(int)
    {
        MyInteger temp=*this;
        --m_Num;
        return temp;
        
    }

private:
    int m_Num;
};

ostream & operator<<(ostream& out,MyInteger myint)
{
    cout<<myint.m_Num;
    return out;
}

void test01()
{
    MyInteger myint;
    cout<<--myint<<endl;
}

void test02()
{
    MyInteger myint;
    cout<<myint--<<endl;
    cout<<myint<<endl;
}


int main()
{
    test01();
    test02();
    return 0;
}