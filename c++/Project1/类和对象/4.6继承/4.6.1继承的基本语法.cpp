#include<iostream>
using namespace std;

//ʵ����ͨҳ��
class BasePage
{
public:
    void header()
    {
        cout<<"��ҳ�������Ρ���¼��ע��...(����ͷ��)"<<endl;
    }
    void footer()
    {
        cout<<"�������ġ�����������վ�ڵ�ͼ...(�����ײ�)"<<endl;
    }

    void left()
    {
        cout<<"Java��Python��C++....(���������б�)"<<endl;

    }
};
//Javaҳ��

class Java : public BasePage
{
public:
    void content()
    {
        cout<<"Javaѧ����Ƶ"<<endl;
    }

};


//Pythonҳ��
class Python : public BasePage
{
public:
    void content()
    {
        cout<<"Pythonѧ����Ƶ"<<endl;
    }
};

class CPP : public BasePage
{
public:
    void content()
    {
        cout<<"C++ѧ����Ƶ"<<endl;
    }
};


//�̳�ʵ��ҳ��


void test01()
{
    cout<<"Java������Ƶҳ��"<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout<<"Python������Ƶҳ��"<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
}

int main()
{
    test01();
    return 0;
}
