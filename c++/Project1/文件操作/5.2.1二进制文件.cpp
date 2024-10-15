#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//二进制文件 写文件
class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    //包含头文件
    //创建流对象

    ofstream ofs;

    //打开文件

    ofs.open("person.txt",ios::out | ios::binary);  //也可以直接ofs("person.txt",ios::out | ios::binary);

    //写文件

    Person p = {"张三",18};
    ofs.write((const char*)&p,sizeof(Person)); //通过write函数以二进制方式写数据
}

int main()
{
    test01(); 
    return 0;
}