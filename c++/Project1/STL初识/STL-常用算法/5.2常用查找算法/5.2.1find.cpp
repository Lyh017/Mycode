#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//���ò����㷨find ����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

//����������������
void test01()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
       v1.push_back(i); 
    }
    //�����Ƿ���5
    auto it=find(v1.begin(),v1.end(),5);
    if(it!=v1.end())
    {
        cout<<"�ҵ���"<<*it<<endl;

    }
    else{
        cout<<"û���ҵ�"<<endl;
    }
}

//�����Զ�����������
class Person
{
public:
    string m_Name;
    int m_Age;

    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }

    //�����Զ����������� ����һ��== ��find֪����ζԱ�Person
    bool operator==(const Person& p)
    {
        if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test02()
{
    vector<Person>v2;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("FFF",50);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    //����p2
    vector<Person>::iterator it=find(v2.begin(),v2.end(),p2);
    if(it!=v2.end())
    {
        cout<<"�ҵ���"<<it->m_Name<<it->m_Age<<endl;

    }
    else{
        cout<<"û���ҵ�"<<endl;
    }
}
int main()
{
    //test01();
    test02();
    return 0;
}