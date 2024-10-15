#include<iostream>
using namespace std;

//动物类
class Animal
{
public:
    int m_Age;
};

//利用虚继承 解决菱形继承问题
//继承之前 加上关键字 virtual 变为虚继承
//Animal类称为虚基类
//羊类
class Sheep : virtual public Animal{};

//驼类
class Camel : virtual public Animal{};

//羊驼类
class Alpaca : public Sheep,public Camel
{

};

void test01()
{
    Alpaca ac;
    ac.Sheep::m_Age=18;
    ac.Camel::m_Age=28;
    //当出现菱形继承的时候，两个父类拥有相同数据，需要加作用域区分
    cout<<"ac.Sheep::m_Age = "<<ac.Sheep::m_Age<<endl;
    cout<<"ac.Camel::m_Age = "<<ac.Camel::m_Age<<endl;
    //cout<<ac.m_Age<<endl; 也可以

    //这份数据我们知道只要有一份就可以，菱形继承导致数据有两份，资源浪费

}

int main()
{
    test01();
    return 0;
}