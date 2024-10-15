#include<iostream>
using namespace std;

//继承方式

//公共继承
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;

};

class Son1 : public Base1
{
public:
    void func()
    {
        m_A=10; //父类中的公共权限成员 到子类中依然是公共权限

        m_B=10; //儿子可以访问父亲中的保护内容 父类中的保护权限成员 到子类中仍然是保护权限

        //m_C=10;  父亲类中的私有成员 子类访问不到
    }



};

void test01()
{
    Son1 s1;
    s1.m_A=100;
    //s1.m_B;  m_B是一个保护权限 类外访问不到

}


//保护继承
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;

};


class Son2 : protected Base2
{
public:
    void func()
    {
        m_A=100;    //父类中公共成员 子类中变为保护权限
        m_B=100;    //父类中保护成员 子类中变成保护权限
        //m_C=100;  父类中私有成员 子类访问不到
    }
};

void test02()
{
    Son2 s2;
    //s2.m_A=100;  //在Son2中 m_A变为保护权限，类外访问不到

}

//私有继承
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;

};

class Son3 : private Base3
{
public:
    void func()
    {
        m_A=10;   //父类中公共成员 到子类变成私有成员
        m_B=10;   //父类中保护成员 到子类变成私有成员
        //m_C=10;  父类中私有成员，子类访问不到

    }

};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        //m_A=10;   表示Son3的属性变为私有，即使儿子也访问不到
    }
};


void test03()
{
    Son3 s3;
    //s3.m_A=1000;
}


int main()
{

    return 0;
}