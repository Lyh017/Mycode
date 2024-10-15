#include<iostream>
using namespace std;



//递增运算符重载 ++

//自定义整型
class MyInteger
{
    friend ostream & operator<<(ostream& out,MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    //重载前置++运算符

    MyInteger& operator++()  //返回&是为了一直对一个数据进行递增操作
    {
        m_Num++;
        return *this;
    }

    //重载后置++运算符
    MyInteger operator++(int)  //int是一个占位参数，可以用于区分前置和后置递增,这里返回的值，因为temp是一个局部变量，当前函数执行完就被销毁
    {   
        //先 记录当时结果
        MyInteger temp = *this;
        //后递增
        m_Num++;
        //最后将记录结果返回
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