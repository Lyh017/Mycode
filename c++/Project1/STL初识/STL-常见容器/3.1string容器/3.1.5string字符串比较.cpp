#include<iostream>
using namespace std;
#include<string>


//�ַ���֮��ıȽ�
//�ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
// = ����0 ��> ���� 1 ��< ���� -1

void test01()
{
    string str1="xello";
    string str2="yello";
    if(str1.compare(str2)==0)
    {
        cout<<"str1����str2"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<<"str1����str2"<<endl;
    }
    else{
        cout<<"str1С��str2"<<endl;
    }
}

int main()
{
    test01();
    return 0;

}