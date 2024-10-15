#include<iostream>
using namespace std;
#include <string>


//类做友元

class Building
{
friend class GoodGay; //GoodGay类是本类的好朋友，可以访问本类中私有成员
public:
    Building();
    string m_SittingRoom;
private:
    string m_BedRoom;
};

class GoodGay
{
public:
    GoodGay();
    Building* building;
    void visit(); //参观函数访问Building中的属性
};

//类外写成员函数
Building::Building()
{

    m_BedRoom="卧室";
    m_SittingRoom="客厅";
    
}

GoodGay::GoodGay()
{
    //创建建筑物的对象
    building = new Building;

}

void GoodGay::visit()
{
    cout<<"好朋友正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好朋友正在访问："<<building->m_BedRoom<<endl;
}


void test01()
{
    GoodGay gg;
    gg.visit();
}




int main()
{
    test01();
    return 0;
}