#include<iostream>
#include<string>
using namespace std;

//�����������������

//��ӡ�����
class MyPrint
{
public:
    //���غ������������
    void operator()(string test)
    {
        cout<<test<<endl;
    }

};


void test01()
{
    MyPrint myprint;
    myprint("hello world");  //����ʹ�������ǳ������ں������ã���˱���Ϊ�º���
    myprint.operator()("Jerry");

}

//�º����ǳ���û�й̶���д��
//�ӷ���
class MyAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};


void test02()
{
    MyAdd add;
    int ret = add(3,4);
    int ret = add.operator()(3,4);
    cout << ret << endl;

    //������������
    cout << MyAdd()(100,100) << endl;

}


int main()
{

    test01();
    test02();
    return 0;
}