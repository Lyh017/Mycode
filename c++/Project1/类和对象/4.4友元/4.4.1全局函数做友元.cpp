#include<iostream>
using namespace std;
#include <string>


class Building
{

friend void goodGay(Building* building);
public:
    Building()
    {
        m_BedRoom="卧室";
        m_SittingRoom="客厅";
    }
    string m_SittingRoom;
private:
    string m_BedRoom;
};


//全局函数
void goodGay(Building* building)
{
    cout<<"好朋友的全局函数 正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好朋友的全局函数 正在访问："<<building->m_BedRoom<<endl;
}



void test01()
{
    Building building;
    goodGay(&building);

}


int main()
{
    test01();
    return 0;
}