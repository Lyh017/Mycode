#include<iostream>
#include<string>
using namespace std;


//�������ʹ�������
class Animal
{
public:
    virtual void speak()=0;
    Animal()
    {
        cout<<"Animal�Ĺ��캯��"<<endl;
    }

    //������������� ����ָ���ͷ��������ʱ���ɾ�������
    // virtual ~Animal()
    // {
    //     cout<<"Animal����������"<<endl;
    // }


    //��������  ��Ҫ����Ҳ��Ҫʵ�� ���˴��������������Ҳ�ǳ����࣬�޷�ʵ�������� 
    virtual ~Animal()=0;

};

Animal::~Animal()
{
    cout<<"Animal�Ĵ�����������"<<endl;
}


class Cat : public Animal
{
public:

    Cat(string name)
    {
        cout<<"Cat�Ĺ��캯��"<<endl;
        m_Name=new string(name);
    }
    virtual void speak()
    {
        cout<<*m_Name<<"��������"<<endl;
    }

    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout<<"Cat������������"<<endl;
            delete m_Name;
            m_Name=NULL;
        }
    }

    string* m_Name;
};

void test01()
{
    Animal* animal=new Cat("Tom");
    animal->speak();
    //����ָ����������ʱ�� ��������������������� ������������ж������� �����ڴ�й¶
    delete animal;
}


int main()
{
    test01();
    return 0;
}


//�ܽ�:
//1.�����ʹ������������������ͨ������ָ���ͷ��������
//2.���������û�ж������ݣ����Բ�дΪ���������ߴ�������
//3.ӵ�д���������������Ҳ���ڳ�����



