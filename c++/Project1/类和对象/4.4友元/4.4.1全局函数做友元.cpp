#include<iostream>
using namespace std;
#include <string>


class Building
{

friend void goodGay(Building* building);
public:
    Building()
    {
        m_BedRoom="����";
        m_SittingRoom="����";
    }
    string m_SittingRoom;
private:
    string m_BedRoom;
};


//ȫ�ֺ���
void goodGay(Building* building)
{
    cout<<"�����ѵ�ȫ�ֺ��� ���ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"�����ѵ�ȫ�ֺ��� ���ڷ��ʣ�"<<building->m_BedRoom<<endl;
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