#include<iostream>
using namespace std;

//1.������Ƴ�ͻ
//2.���ض�������this

class Person
{
public:
    Person(int age)
    {
        //thisָ��ָ�򱻵��õĳ�Ա���� �����Ķ��������������p1�ڵ��������Ա����
       this->age=age;  
    }

    Person& PersonAddAge(Person &p)
    {
        this->age+=p.age;
        return *this;  //thisָ��p2��ָ�룬��*thisָ��ľ���p2���������
    }

    int age;
};

void test01()
{
    Person p1(18);
    cout<<"p1�����䣺"<<p1.age<<endl;
}

//���ض����� *this
void test02()
{
    Person p1(10);

    Person p2(10);
    cout<<(int*)&p2<<endl;
    

    p2.PersonAddAge(p1).PersonAddAge(p1);

    cout<<"p2������Ϊ��"<<p2.age<<endl;
    cout<<(int*)&p2.PersonAddAge(p1).PersonAddAge(p1)<<endl;
    

}






int main()
{

    //test01();
    test02();
    system("pause");
    return 0;
}