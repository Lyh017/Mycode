#include<iostream>
using namespace std;

//�������캯���ĵ���ʱ��
//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//2.ֵ���ݵķ�ʽ������������ֵ
//3.ֵ��ʽ���ؾֲ�����


class Person
{
public:
    Person()
    {
        cout<<"PersonĬ�Ϲ��캯������"<<endl;
    }

    Person(int age)
    {
        cout<<"Person�вι��캯������"<<endl;
        m_Age=age;
    }

    Person(const Person &p)
    {
        cout<<"Person�������캯������"<<endl;
        m_Age=p.m_Age;
    }

    ~Person()
    {
        cout<<"Person������������"<<endl;

    }

    int m_Age;
};


//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
    Person p1(20);
    Person p2(p1);

    cout<<"p2������Ϊ��"<<p2.m_Age<<endl;
}

//void doWork(Person p)
//{

//}

//2.ֵ���ݵķ�ʽ������������ֵ
void test02()
{
    Person p;
    //doWork(p);

}


//3.ֵ��ʽ���ؾֲ�����
Person  doWork2()
{
    Person p1;
    cout<<(int*)&p1<<endl;
    return Person(p1);  //ֱ��return p1�����ܻᾭ���������Ż�����������Լ������Ŀ������죬���ҵ�ַ��ͬ
}

void test03()
{
    Person p3=doWork2();  //Person p3=Person(p1)
    cout<<(int*)&p3<<endl;
}

int main()
{
    //test01()
    //test02();
    test03();
    return 0;
}


