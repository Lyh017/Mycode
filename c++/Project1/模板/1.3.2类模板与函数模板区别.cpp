#include<iostream>
#include<string>
using namespace std;

//��ģ���뺯��ģ������
template<class NameType,class AgeType=int>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        m_Age=age;
        m_Name=name;
    }

    void showPerson()
    {
        cout<<"name = "<<m_Name<<" age = "<<m_Age<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

//��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test01()
{
    //Person p("Maker",10);  //�޷��Ƶ���ģ�����
    Person<string,int> p("Maker",10); //ֻ������ʾָ������
    p.showPerson();
}


//��ģ����ģ������б��п�����Ĭ�ϲ���
void test02()
{
    Person<string> p1("Tony",20);
    p1.showPerson();

}


int main()
{
    //test01();
    test02();
    return 0;
}