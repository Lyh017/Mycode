#include<iostream>
using namespace std;
#include<string>

//string�ַ���ƴ��
//string�ڲ�������+=

void test01()
{
    string str1="��";
    str1+="������Ϸ";
    cout<<"str1="<<str1<<endl;

    str1+=":";   //׷��һ���ַ�
    cout<<"str1="<<str1<<endl;

    string str2="LOL APEX";
    str1+=str2;
    cout<<"str1="<<str1<<endl;


    string str3="I";
    str3.append(" love ");
    cout<<"str3="<<str3<<endl;

    str3.append("game abcd",4);  //���ַ���ǰn���ַ����ӵ���ǰ�ַ�����β
    cout<<"str3="<<str3<<endl;

    //str3.append(str2);
    cout<<"str3="<<str3<<endl;

    str3.append(str2,4,4);  //string& append(const string &s,int pos,int n),�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
    cout<<"str3="<<str3<<endl;
}

int main()
{
    test01();
    return 0;
}