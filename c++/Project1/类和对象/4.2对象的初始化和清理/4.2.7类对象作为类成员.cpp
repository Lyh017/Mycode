#include<iostream>
#include<string>
using namespace std;

//�������Ϊ���Ա

class Phone
{
public:

    Phone(string pName)
    {
        m_PName=pName;
        cout<<"Phone�Ĺ��캯���ĵ���"<<endl;
    }

    string m_PName;

    ~Phone()
    {
        cout<<"Phone�����������ĵ���"<<endl;
    }
};


class Person
{
public:

    Person(string name,string pName):m_Name(name),m_Phone(pName) //Phone m_Phone = pName ��ʽת����
    {
        cout<<"Person�Ĺ��캯������"<<endl;
    }
    //����
    string m_Name;

    //�ֻ�
    Phone m_Phone;

    ~Person()
    {
        cout<<"Person��������������"<<endl;
    }
};

void test01()
{
    Person p("����","iPhone 15 promax");
    cout<<p.m_Name<<"���ţ�"<<p.m_Phone.m_PName<<endl;

}
//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ������������෴

int main()
{
    test01();
    return 0;
}


















