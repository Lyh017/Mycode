#include<iostream>
using namespace std;

//1.解决名称冲突
//2.返回对象本身用this

class Person
{
public:
    Person(int age)
    {
        //this指针指向被调用的成员函数 所属的对象，例如这里就是p1在调用这个成员函数
       this->age=age;  
    }

    Person& PersonAddAge(Person &p)
    {
        this->age+=p.age;
        return *this;  //this指向p2的指针，而*this指向的就是p2这个对象本体
    }

    int age;
};

void test01()
{
    Person p1(18);
    cout<<"p1的年龄："<<p1.age<<endl;
}

//返回对象本身 *this
void test02()
{
    Person p1(10);

    Person p2(10);
    cout<<(int*)&p2<<endl;
    

    p2.PersonAddAge(p1).PersonAddAge(p1);

    cout<<"p2的年龄为："<<p2.age<<endl;
    cout<<(int*)&p2.PersonAddAge(p1).PersonAddAge(p1)<<endl;
    

}






int main()
{

    //test01();
    test02();
    system("pause");
    return 0;
}