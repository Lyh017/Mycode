#include<iostream>
using namespace std;
#include<string>

//�ַ������Һ��滻

//1.����
void test01()
{
    string str1 ="abcdefgde";
    int pos = str1.find("de");
    if(pos==-1)
    {
        cout<<"δ�ҵ��ַ���"<<endl;
    }
    else
    {
        cout<<"�ҵ��ַ���,pos="<<pos<<endl;
    }
    
    //rfind ��find����
    //rfind����������ң�find�������Ҳ���
    int pos1=str1.rfind("de");
    cout<<"pos1="<<pos1<<endl;

}

//2.�滻
void test02()
{
    string str1="abcdefg";
    str1.replace(1,3,"1111");  //string& replace(int pos,int n,const string& str ),������stringҲ������char* ���滻��pos��ʼ��n���ַ�
    cout<<str1<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}