#include<iostream>
using namespace std;

//�����ǳ����

class Person
{
public:
    Person()
    {
        cout<<"PersonĬ�Ϲ��캯������"<<endl;
    }

    Person(int age,int height)
    {
        cout<<"Person�вι��캯������"<<endl;
        m_Age=age;
        m_Height = new int(height);
    }

    //�Լ�ʵ�ֿ������캯�� ���ǳ��������������
    Person(const Person &p)
    {
        cout<<"Person�������캯������"<<endl;
        m_Age=p.m_Age;
        //m_Height=p.m_Height ������Ĭ��ʵ�־�������
        //�������

        m_Height=new int(*p.m_Height);
    }

    ~Person()
    {
        //�������룬���������ٵ������ͷ�
        cout<<"Person������������"<<endl;
        if(m_Height != NULL)
        {
            delete m_Height;
            m_Height=NULL;
        }
        //ǳ����������������Ƕ����ڴ��ظ��ͷ�
    }

    int m_Age;
    int* m_Height;
};

void test01()
{
    Person p1(18,170);
    cout<<"p1������Ϊ��"<<p1.m_Age<<"���Ϊ��"<<*(p1.m_Height)<<endl;

    Person p2(p1);   //������ñ������ṩ�Ŀ������캯��������ǳ��������
    cout<<"p2������Ϊ��"<<p2.m_Age<<"���Ϊ��"<<*(p2.m_Height)<<endl;
}


int main()
{
    test01();

    system("pause");
    return 0;
}