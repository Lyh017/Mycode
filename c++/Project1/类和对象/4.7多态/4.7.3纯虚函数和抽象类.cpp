#include<iostream>
using namespace std;


//纯虚函数和抽象类
class Base
{
public:

    virtual void func() = 0; //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类

    //抽象类特点:
    //1.无法实例化对象
    //2. 抽象类的子类 必须要重写父类中的纯虚函数 否则也属于抽象类
};

class Son : public Base
{
public:

    void func()
    {
        cout<<"func函数调用"<<endl;
    }

};


void test01()
{
    Base* base = new Son;
    base->func();
}



int main()
{
    test01();
    return 0;
}