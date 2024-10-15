#include<iostream>
using namespace std;
#include <string>

class Building;
class GoodGay
{
public:
    GoodGay();
    Building* building;
    void visit(); //参观函数访问Building中的属性
    void visit2(); //让visit2不可以访问Building中私有成员
};


class Building
{
friend void GoodGay::visit(); //GoodGay类下visit函数作为本类的好朋友
public:
    Building();
    string m_SittingRoom;
private:
    string m_BedRoom;
};

Building::Building()
{
    m_BedRoom="卧室";
    m_SittingRoom="客厅";
}

GoodGay::GoodGay()
{
    building=new Building;
}

void GoodGay::visit()
{
    cout<<"好朋友正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好朋友正在访问："<<building->m_BedRoom<<endl;
}

void GoodGay::visit2()
{
    cout<<"朋友正在访问："<<building->m_SittingRoom<<endl;
    //cout<<"好朋友正在访问："<<building->m_BedRoom<<endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}


int main()
{
    test01();
    return 0;
}