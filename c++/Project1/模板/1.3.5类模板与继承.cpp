#include<iostream>
#include<string>
using namespace std;

//类模板与继承

template<class T>
class Base
{
public:
    T m;
};

class Son : public Base<int>   //必须要知道父类中的T的类型，才能继承给子类
{

};

void test01()
{
    //Son s1;
}

//如果想灵活指定父类中T的类型，子类也需要变成类模板
template<class T1,class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout<<"T2的类型是:"<<typeid(T2).name()<<endl;
        cout<<"T1的类型是:"<<typeid(T1).name()<<endl;
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

//总结，如果父类是类模板，子类需要指定出父类中T的数据类型