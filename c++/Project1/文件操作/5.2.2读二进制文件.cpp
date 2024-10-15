#include<iostream>
#include<fstream>

using namespace std;

class Person
{
    public:
    char m_Name[64];
    int m_Age;
};

//读文件 调用成员函数read
void test01()
{
    //头文件
    //流对象

    ifstream ifs;

    //打开文件并判断是否打开成功

    ifs.open("person.txt",ios::in | ios::binary);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    //读文件

    Person p;
    ifs.read((char*)&p,sizeof(Person));
    cout<<"姓名："<<p.m_Name<<" 年龄："<<p.m_Age<<endl;

    //关闭文件


}




int main()
{
    test01();
    return 0;
}