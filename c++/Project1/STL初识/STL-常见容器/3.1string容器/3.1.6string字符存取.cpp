#include<iostream>
using namespace std;
#include<string>

//string�ַ���ȡ
void test01()
{
    string str="hello";

    //cout<<"str="<<str<<endl;

    //1.ͨ��[]���ʵ����ַ�
    for(int i=0;i<5;i++)  //i.size()
    {
        cout<<str[i]<<' ';
    }
    cout<<endl;

    //2.ͨ��at�ķ�ʽ���ʵ����ַ�
    for(int i=0;i<5;i++)
    {
        cout<<str.at(i)<<' ';
    }
    cout<<endl;

    //�޸ĵ����ַ�
    str[0]='x';
    cout<<"str="<<str<<endl;

    str.at(1)='x';
    cout<<"str="<<str<<endl;
}


int main()
{
    test01();
    return 0;
}
