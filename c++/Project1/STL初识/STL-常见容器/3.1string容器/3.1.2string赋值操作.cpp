#include<iostream>
using namespace std;
#include<string>

// string& operator=(const char* s);    //char*���͵��ַ��� ��ֵ����ǰ���ַ���
// string& operator=(const string &s);  //���ַ���s������ǰ�ַ���
// string& operator=(char c);         //�ַ�������ǰ�ַ���
// string& assgin(const char* s);      //���ַ���s������ǰ�ַ���
// string& assgin(const string &s);    //���ַ���s������ǰ�ַ���
// string& assgin(const char* s,int n);  //���ַ���s��ǰn��������ǰ�ַ���
// string& assgin(int n,char c);        //��n���ַ�c������ǰ�ַ���


void test01()
{
    string str1;
    str1="hello world";
    cout<<"str1="<<str1<<endl;

    string str2;
    str2=str1;
    cout<<"str2="<<str2<<endl;

    string str3;
    str3='a';

    string str4;
    str4.assign("hello,c++");
    cout<<"str4="<<str4<<endl;

    string str5;
    str5.assign("hello,c++",5);
    cout<<"str5="<<str5<<endl;
    
    string str6;
    str6.assign(str5);

    string str7;
    str7.assign(10,'w');
    cout<<"str7="<<str7<<endl;
}

int main()
{
    test01();
    return 0;
}