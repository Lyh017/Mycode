#include<iostream>
using namespace std;


//��̬
//��̬��̬:�������غ�������������ھ�̬��̬�����ú�����
//��̬��̬:��������麯��ʵ������ʱ��̬

//������
class Animal
{
public:
    //�麯��
    virtual void speak()
    {
        cout<<"������˵��"<<endl;
    }

};

//è��
class Cat : public Animal
{
public:
    //��д  ��������ֵ���� ������ �����б� ��ȫ��ͬ
    void speak()   //�ɼ�virtualҲ���Բ���
    {
        cout<<"������"<<endl;
    }
};


//����
class Dog : public Animal
{
public:
    void speak(){
        cout<<"������"<<endl;
    }

};

//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵���������������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���

//��̬��̬��������
//1.�м̳й�ϵ
//2.������д������麯��

//��̬��̬ʹ��
// �����ָ��������� ָ���������


void doSpeak(Animal& animal) //Animal& animal = cat
{
    animal.speak();
}


void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

int main()
{
    test01();
    return 0;
}