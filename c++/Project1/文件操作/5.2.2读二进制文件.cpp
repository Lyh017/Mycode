#include<iostream>
#include<fstream>

using namespace std;

class Person
{
    public:
    char m_Name[64];
    int m_Age;
};

//���ļ� ���ó�Ա����read
void test01()
{
    //ͷ�ļ�
    //������

    ifstream ifs;

    //���ļ����ж��Ƿ�򿪳ɹ�

    ifs.open("person.txt",ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout<<"�ļ���ʧ��"<<endl;
        return;
    }

    //���ļ�

    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout<<"������"<<p.m_Name<<" ���䣺"<<p.m_Age<<endl;

    //�ر��ļ�


}




int main()
{
    test01();
    return 0;
}