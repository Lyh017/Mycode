#include<iostream>
using namespace std;
#include<string>

//string���ִ�

void test01()
{
    string str="abcdef";
    string sub=str.substr(1,3);
    cout<<"sub="<<sub<<endl;

}

//ʵ�ò���
void test02()
{
    string email="zhangsan@sina.com";

    //���ʼ���ַ��ȡ�û���

   int pos=email.find('@');
   string name=email.substr(0,pos); //��һ���Ǵ��ĸ�λ���𣬵ڶ����ǽض��ٸ��ַ��������±�
   cout<<name<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}