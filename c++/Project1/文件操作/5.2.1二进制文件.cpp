#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//�������ļ� д�ļ�
class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    //����ͷ�ļ�
    //����������

    ofstream ofs;

    //���ļ�

    ofs.open("person.txt",ios::out | ios::binary);  //Ҳ����ֱ��ofs("person.txt",ios::out | ios::binary);

    //д�ļ�

    Person p = {"����",18};
    ofs.write((const char*)&p,sizeof(Person)); //ͨ��write�����Զ����Ʒ�ʽд����
}

int main()
{
    test01(); 
    return 0;
}