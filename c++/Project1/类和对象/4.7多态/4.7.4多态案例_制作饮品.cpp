#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
    //��ˮ
    virtual void Boil()=0;
    //����
    virtual void Brew()=0;
    //���뱭��
    virtual void PourInCup()=0;
    //���븨��
    virtual void AddSome()=0;

    //������Ʒ
    void MakeDrink()
    {
        Boil();
    
        Brew();
   
        PourInCup();
    
        AddSome();
    }

    virtual ~AbstractDrinking()
    {
        
    }
};


//��������
class Coffee : public AbstractDrinking
{
public:
    //��ˮ
    virtual void Boil()
    {
        cout<<"���Ȫˮ"<<endl;
    }
    //����
    virtual void Brew()
    {
        cout<<"���ݿ���"<<endl;
    }
    //���뱭��
    virtual void PourInCup()
    {
        cout<<"���뱭��"<<endl;
    }
    //���븨��
    virtual void AddSome()
    {
        cout<<"�����Ǻ�ţ��"<<endl;
    }


};


//��������
class Tea : public AbstractDrinking
{
public:
     //��ˮ
    virtual void Boil()
    {
        cout<<"��׿�ˮ"<<endl;
    }
    //����
    virtual void Brew()
    {
        cout<<"���ݲ�Ҷ"<<endl;
    }
    //���뱭��
    virtual void PourInCup()
    {
        cout<<"����豭"<<endl;
    }
    //���븨��
    virtual void AddSome()
    {
        cout<<"�������"<<endl;
    }

};

void doWork(AbstractDrinking* drink)
{
    drink->MakeDrink();
    delete drink;
}


void test01()
{
    //��������
    doWork(new Coffee);
    
    //������
    doWork(new Tea);
}


int main()
{

    test01();
    return 0;
}