#include<iostream>
using namespace std;
#include <string>


//������Ԫ

class Building
{
friend class GoodGay; //GoodGay���Ǳ���ĺ����ѣ����Է��ʱ�����˽�г�Ա
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
    void visit(); //�ιۺ�������Building�е�����
};

//����д��Ա����
Building::Building()
{

    m_BedRoom="����";
    m_SittingRoom="����";
    
}

GoodGay::GoodGay()
{
    //����������Ķ���
    building = new Building;

}

void GoodGay::visit()
{
    cout<<"���������ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"���������ڷ��ʣ�"<<building->m_BedRoom<<endl;
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